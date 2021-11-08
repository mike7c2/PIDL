# PIDL (Peripheral Interface Description Library)

PIDL is an experiement to try using a description similar to an SVD file for the register
maps of other devices. Initially considering I2C devices but the concept should be extendable
to arbitrary devices with register based interfaces.

## TL;DR

### Usage

The project is not yet in a proper package.. check it out, install the deps:

```
pip3 install jinja2 yaml
```

The run the main file `pidl.py` i.e.:

```
python3 pidl.py --help
usage: pidl.py [-h] [-c] file

PIDL Parser and generator

positional arguments:
  file              PIDL file to parse

optional arguments:
  -h, --help        show this help message and exit
  -c, --generate-c  Enable generation of C
```

And try to generate C with one of the example device descriptions:

```
python3 pidl.py devices/tmp102.pidl -c
```

### Example input and generation

 * [ina219.pidl](devices/ina219.pidl) and example output [ina219.h](gen/ina219.h)
 * [tmp102.pidl](devices/tmp102.pidl) and example output [tmp102.h](gen/tmp102.h)
 * [mlx90640.pidl](devices/mlx90640.pidl) and example output [mlx90640.h](gen/mlx90640.h)

#### Awkward examples
The PCF8574 is an awkward device to describe with PIDL, it doesn't have a register/address
based interface with reads and writes being sent immediately to the input and output buffers.

The example is included to give food for thought and currently has an `addressSize` of 0 which 
could be a way of dealing with this. There are other sensors too which don't use a register based
interface so we probably do want a way to deal with this.

 * [tmp102.pidl](devices/pcf8574.pidl) and example output [pcf8574.h](gen/pcf8574.h)

## Goals

To have a format which can be used to accurately describe the register interface of a device in a machine
readable way. This is to be focussed on the "what" of the register map more than the behaviour of the device
to keep the project feasible.

To have a set of tools which can consume the format. These tools include:

 * Generators i.e. generate device definitions in various langauge
 * Dynamic consumers i.e. a generic driver which could be used in python to talk to registers on any device
 * Documentation Generation - if there were good tools to generate documentation from these descriptions maybe manufacturers would ship them..

Considerations:

 * Should the library seek to cover peripherals more generally, including awkward devices like pcf8574 which does not have a register based interface?
 * Better handling of complicated memory layouts - could the pixel layouts in mlx90640 be expressed?

## The PIDL description format

PIDL is a YAML based format which takes structure almost directly from SVD

The format records in a structured way the definition of the interface for a peripheral, some meta data such as how big its address words are
and the datasheet that was used to create the PIDL defintion.

The format of a PIDL definition is:

```
device:
    name: The name of the device
    description: A long description name
    datasheet:
        link: Link to datasheet used to make definition
        title: Title of datasheet
        revision: Revision of datasheet
    addressWidth: An integer which is the number of bits used to address a register on the device
    registerSize: The size of each register at an address
    regions:
        -region:
            name: Name of first region
            offset: Offset of first region (hex)
            size: Size of the region
        -region #....... More regions
    registers:
        -register:
            name: Name of the register
            description: Description of what register does
            offset: Offset of the register in the address map (hex)
            size: Size of the register in bits
            fields: # Optional list of fields
                -field:
                    name: Name of the bitfield
                    description: Description of the bitfield
                    bitRange: Bit range for field: "[first_bit:last_bit]"
                    enumeratedValues: # Optional list of enumerated values for field
                        - enumeratedValue:
                            name: Name of enumerated value
                            description: Description of enumerated value
                            value: The value for this entry in the enumeration
                        - enumeratedValue: #.... More enumerated values
                -field #.... More fields
        -register: #...... More registers!
```

## Current TODO:

 * Make more devices
 * Rust parser/generator?

