import yaml
import dicttoxml

def find_or_default(collection, key, default):
    if key in collection:
        return collection[key]
    else:
        return default


class RIDLParseException(Exception):
    pass

class RIDLDevice(object):
    def __init__(self, name : str, description : str, datasheet, registers):
        self.name = name
        self.description = description
        self.datasheet = datasheet
        self.registers = registers

    @staticmethod
    def parse(node, parent_list):
        try:
            name = node["name"]
            description = find_or_default(node, "description", "")
            datasheet = node["datasheet"]

            parent_list.append(name)

            registers = []
            if "registers" in node:
                for r in node["registers"]:
                    registers.append(RIDLRegister.parse(r["register"], parent_list))

            return RIDLDevice(name, description, datasheet, registers)
        except KeyError as k:
            raise RIDLParseException("Missing key %s in subelement %s" % (str(k), ".".join(parent_list)))

class RIDLRegister(object):
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

            parent_list.append(name)
            fields = []
            if "fields" in node:
                for f in node["fields"]:
                    fields.append(RIDLField.parse(f["field"], parent_list))

            return RIDLRegister(name, description, offset, size, fields)
        except KeyError as k:
            raise RIDLParseException("Missing key %s in subelement %s" % (str(k), ".".join(parent_list)))

class RIDLField(object):
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

            parent_list.append(name)
            bitRange = RIDLBitRange.parse(node["bitRange"], parent_list)
            enumeratedValues = []
            if "enumeratedValues" in node:
                for e in node["enumeratedValues"]:
                    enumeratedValues.append(RIDLEnumeratedValue.parse(e["enumeratedValue"], parent_list))

            return RIDLField(name, description, bitRange, enumeratedValues)
        except KeyError as k:
            raise RIDLParseException("Missing key %s in subelement %s" % (str(k), ".".join(parent_list)))

class RIDLEnumeratedValue(object):
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

            return RIDLEnumeratedValue(name, description, value)
        except KeyError as k:
            raise RIDLParseException("Missing key %s in subelement %s" % (str(k), ".".join(parent_list)))

class RIDLBitRange(object):
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
            return RIDLBitRange(int(start), int(stop))
        except KeyError as k:
            raise RIDLParseException("Missing key %s in subelement %s" % (str(k), ".".join(parent_list)))

def parse_ridl(path):
    with open(path, "r") as f:
        root = yaml.load(f, Loader=yaml.Loader)
        return RIDLDevice.parse(root["device"], ["root"])

if __name__ == "__main__":
    try:
        parse_ridl("devices/ina219.ridl")
    except RIDLParseException as p:
        print(str(p))
