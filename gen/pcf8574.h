/**
 * Automatically generated code by pidl
 * Definition generated using:
 *     https://www.ti.com/lit/ds/symlink/pcf8574.pdf
 *     PCF8574 Remote 8-Bit I/O Expander for I2C Bus
 *     SCPS068J –JULY 2001–REVISED MARCH 2015
 */
/**
 * This is a set of register definitions for PCF8574
 *
 * This 8-bit input/output (I/O) expander for the two-line bidirectional bus 
 * (I2C) is designed for 2.5-V to 6-V VCC operation. The PCF8574 device provides 
 * general-purpose remote I/O expansion for most microcontroller families by way 
 * of the I2C interface [serial clock (SCL), serial data (SDA)]. The device 
 * features an 8-bit quasi-bidirectional I/O port (P0–P7), including latched 
 * outputs with high- current drive capability for directly driving LEDs. Each 
 * quasi-bidirectional I/O can be used as an input or output without the use of 
 * a data-direction control signal. At power on, the I/Os are high. In this 
 * mode, only a current source to VCC is active.
 */
#ifndef PCF8574_H
#define PCF8574_H

/**
 * Definitions for Data register
 *
 * Reads to this register read the device pins, write to it set the output 
 * values 
*/


#endif