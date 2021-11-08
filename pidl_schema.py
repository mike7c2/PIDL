import yaml

def find_or_default(collection, key, default):
    if key in collection:
        return collection[key]
    else:
        return default


class PIDLParseException(Exception):
    pass

class PIDLDevice(object):
    def __init__(self, name : str, description : str, datasheet, registers, regions, addressWidth : int, registerSize : int):
        self.name = name
        self.description = description
        self.datasheet = datasheet
        self.registers = registers
        self.regions = regions

        self.addressWidth = addressWidth
        self.registerSize = registerSize

    @staticmethod
    def parse(node, parent_list):
        try:
            name = node["name"]
            description = find_or_default(node, "description", "")
            datasheet = node["datasheet"]
            addressWidth = node["addressWidth"]
            registerSize = node["registerSize"]

            parent_list = [name] + parent_list
            registers = []
            if "registers" in node:
                for r in node["registers"]:
                    registers.append(PIDLRegister.parse(r["register"], parent_list))
            regions = []
            if "regions" in node:
                for r in node["regions"]:
                    regions.append(PIDLRegion.parse(r["region"], parent_list))

            return PIDLDevice(name, description, datasheet, registers, regions, addressWidth, registerSize)
        except KeyError as k:
            raise PIDLParseException("Missing key %s in subelement %s" % (str(k), ".".join(parent_list)))

class PIDLRegion(object):
    def __init__(self, name : str, description : str, offset : int, size : int):
        self.name = name
        self.description = description
        self.offset = offset
        self.size = size

    @staticmethod
    def parse(node, parent_list):
        try:
            name = node["name"]
            description = find_or_default(node, "description", "")
            offset = node["offset"]
            size = node["size"]
            parent_list = [name] + parent_list

            return PIDLRegion(name, description, offset, size)
        except KeyError as k:
            raise PIDLParseException("Missing key %s in subelement %s" % (str(k), ".".join(parent_list)))

class PIDLRegister(object):
    def __init__(self, name : str, description : str, offset : int, size : int, fields):
        self.name = name
        self.description = description
        self.offset = offset
        self.size = size
        self.fields = fields

    @staticmethod
    def parse(node, parent_list):
        try:
            name = node["name"]
            description = find_or_default(node, "description", "")
            offset = node["offset"]
            size = node["size"]

            parent_list = [name] + parent_list
            fields = []
            if "fields" in node:
                for f in node["fields"]:
                    fields.append(PIDLField.parse(f["field"], parent_list))

            return PIDLRegister(name, description, offset, size, fields)
        except KeyError as k:
            raise PIDLParseException("Missing key %s in subelement %s" % (str(k), ".".join(parent_list)))

class PIDLField(object):
    def __init__(self, name : str, description : str, bitRange : str, enumeratedValues):
        self.name = name
        self.description = description
        self.bitRange = bitRange
        self.enumeratedValues = enumeratedValues

    @staticmethod
    def parse(node, parent_list):
        try:
            name = node["name"]
            description = find_or_default(node, "description", "")

            parent_list = [name] + parent_list
            bitRange = PIDLBitRange.parse(node["bitRange"], parent_list)
            enumeratedValues = []
            if "enumeratedValues" in node:
                for e in node["enumeratedValues"]:
                    enumeratedValues.append(PIDLEnumeratedValue.parse(e["enumeratedValue"], parent_list))

            return PIDLField(name, description, bitRange, enumeratedValues)
        except KeyError as k:
            raise PIDLParseException("Missing key %s in subelement %s" % (str(k), ".".join(parent_list)))

class PIDLEnumeratedValue(object):
    def __init__(self, name : str, description : str, value : int):
        self.name = name
        self.description = description
        self.value = value

    @staticmethod
    def parse(node, parent_list):
        try:
            name = node["name"]
            description = find_or_default(node, "description", "")
            value = node["value"]

            return PIDLEnumeratedValue(name, description, value)
        except KeyError as k:
            raise PIDLParseException("Missing key %s in subelement %s" % (str(k), ".".join(parent_list)))

class PIDLBitRange(object):
    def __init__(self, start : int, stop : int):
        self.start = start
        self.stop = stop

    def width(self):
        return (self.start - self.stop) + 1

    def offset(self):
        return self.stop

    @staticmethod
    def parse(str_value, parent_list):
        try:
            start, stop = str_value.strip("[]").split(":")
            return PIDLBitRange(int(start), int(stop))
        except KeyError as k:
            raise PIDLParseException("Missing key %s in subelement %s" % (str(k), ".".join(parent_list)))

def parse_pidl(path):
    with open(path, "r") as f:
        root = yaml.load(f, Loader=yaml.Loader)
        return PIDLDevice.parse(root["device"], ["root"])
