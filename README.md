# RIDL

RIDL is an experiement to try using a description similar to an SVD file for the register
maps of other devices. Initially considering I2C devices but the concept should be extendable
to arbitrary devices with register based interfaces.

# Usage

The project is not yet in a proper package.. check it out, install the deps:

```
pip3 install jinja2 yaml
```

The run the main file `ridl.py` i.e.:

```
python3 ridl.py --help
usage: ridl.py [-h] [-c] file

RIDL Parser and generator

positional arguments:
  file              RIDL file to parse

optional arguments:
  -h, --help        show this help message and exit
  -c, --generate-c  Enable generation of C
```

And try to generate C with one of the example device descriptions:

```
python3 ridl.py devices/tmp102.ridl -c
```

## Goals

To have a format which can be used to accurately describe the register interface of a device in a machine
readable way. This is to be focussed on the "what" of the register map more than the behaviour of the device
to keep the project feasible

To have a set of tools which can consume the format. These tools include:

Generators i.e. generate device definitions in various langauge
Dynamic consumers i.e. a generic driver which could be used in python to talk to registers on any device
Documentation Generation - if there were good tools to generate documentation from these descriptions maybe manufacturers would ship them..