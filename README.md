# RIDL

RIDL is an experiement to try using a description similar to an SVD file for the register
maps of other devices. Initially considering I2C devices but the concept should be extendable
to arbitrary devices with register based interfaces.

## Goals

To have a format which can be used to accurately describe the register interface of a device in a machine
readable way. This is to be focussed on the "what" of the register map more than the behaviour of the device
to keep the project feasible

To have a set of tools which can consume the format. These tools include:

Generators i.e. generate device definitions in various langauge
Dynamic consumers i.e. a generic driver which could be used in python to talk to registers on any device
Documentation Generation - if there were good tools to generate documentation from these descriptions maybe manufacturers would ship them..