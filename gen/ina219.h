/**
 * Automatically generated code by pidl
 * Definition generated using:
 *     https://www.ti.com/lit/ds/symlink/ina219.pdf
 *     INA219 Zerø-Drift, Bidirectional Current/Power Monitor With I2C Interface
 *     SBOS448G –AUGUST 2008–REVISED DECEMBER 2015
 */
/**
 * This is a set of register definitions for INA219
 *
 * The INA219 is a current shunt and power monitor with an I2C- or 
 * SMBUS-compatible interface. The device monitors both shunt voltage drop and 
 * bus supply voltage, with programmable conversion times and filtering. A 
 * programmable calibration value, combined with an internal multiplier, enables 
 * direct readouts of current in amperes. An additional multiplying register 
 * calculates power in watts. The I 2C- or SMBUS-compatible interface features 
 * 16 programmable addresses. The INA219 is available in two grades: A and B. 
 * The B grade version has higher accuracy and higher precision specifications. 
 * The INA219 senses across shunts on buses that can vary from 0 to 26 V. The 
 * device uses a single 3- to 5.5-V supply, drawing a maximum of 1 mA of supply 
 * current. The INA219 operates from –40°C to 125°C.
 */
#ifndef INA219_H
#define INA219_H

/**
 * Definitions for Configuration register
 *
 * All-register reset, settings for bus, voltage range, PGA Gain, ADC 
 * resolution/averaging 
*/
#define INA219_CONFIGURATION_INDEX ((uint8_t)0x00)

/* Setting this bit to '1' generates a system reset that is the same as power-on reset. Resets all registers to default values; this bit self-clears. */
#define INA219_CONFIGURATION_RST_Pos ((uint16_t)15)
#define INA219_CONFIGURATION_RST_Msk (((uint16_t)0x0001) << INA219_CONFIGURATION_RST_Pos)
#define INA219_CONFIGURATION_RST INA219_CONFIGURATION_RST_Msk

/* Control bus voltage range */
#define INA219_CONFIGURATION_BRNG_Pos ((uint16_t)13)
#define INA219_CONFIGURATION_BRNG_Msk (((uint16_t)0x0001) << INA219_CONFIGURATION_BRNG_Pos)
#define INA219_CONFIGURATION_BRNG INA219_CONFIGURATION_BRNG_Msk
#define INA219_CONFIGURATION_BRNG_FSR16V ((0u) << INA219_CONFIGURATION_BRNG_Pos)        /* 16V FSR*/
#define INA219_CONFIGURATION_BRNG_FSR32V ((1u) << INA219_CONFIGURATION_BRNG_Pos)        /* 32V FSR*/

/* Sets PGA gain and range. */
#define INA219_CONFIGURATION_PG_Pos ((uint16_t)11)
#define INA219_CONFIGURATION_PG_Msk (((uint16_t)0x0003) << INA219_CONFIGURATION_PG_Pos)
#define INA219_CONFIGURATION_PG INA219_CONFIGURATION_PG_Msk
#define INA219_CONFIGURATION_PG_PG00 ((0u) << INA219_CONFIGURATION_PG_Pos)        /* Range +- 40mV*/
#define INA219_CONFIGURATION_PG_PG01 ((1u) << INA219_CONFIGURATION_PG_Pos)        /* Range +- 80mV*/
#define INA219_CONFIGURATION_PG_PG10 ((2u) << INA219_CONFIGURATION_PG_Pos)        /* Range +- 160mV*/
#define INA219_CONFIGURATION_PG_PG11 ((3u) << INA219_CONFIGURATION_PG_Pos)        /* Range +- 320mV*/

/* These bits adjust the Bus ADC resolution (9-, 10-, 11-, or 12-bit) or set the number of samples used when averaging results for the Bus Voltage Register (02h). */
#define INA219_CONFIGURATION_BADC_Pos ((uint16_t)7)
#define INA219_CONFIGURATION_BADC_Msk (((uint16_t)0x000f) << INA219_CONFIGURATION_BADC_Pos)
#define INA219_CONFIGURATION_BADC INA219_CONFIGURATION_BADC_Msk

/* These bits adjust the Shunt ADC resolution (9-, 10-, 11-, or 12-bit) or set the number of samples used when averaging results for the Shunt Voltage Register (01h). */
#define INA219_CONFIGURATION_SADC_Pos ((uint16_t)4)
#define INA219_CONFIGURATION_SADC_Msk (((uint16_t)0x0007) << INA219_CONFIGURATION_SADC_Pos)
#define INA219_CONFIGURATION_SADC INA219_CONFIGURATION_SADC_Msk

/*  */
#define INA219_CONFIGURATION_MODE_Pos ((uint16_t)0)
#define INA219_CONFIGURATION_MODE_Msk (((uint16_t)0x0007) << INA219_CONFIGURATION_MODE_Pos)
#define INA219_CONFIGURATION_MODE INA219_CONFIGURATION_MODE_Msk
#define INA219_CONFIGURATION_MODE_MODE000 ((0u) << INA219_CONFIGURATION_MODE_Pos)        /* Power-down*/
#define INA219_CONFIGURATION_MODE_MODE001 ((1u) << INA219_CONFIGURATION_MODE_Pos)        /* Shunt voltage, triggered*/
#define INA219_CONFIGURATION_MODE_MODE010 ((2u) << INA219_CONFIGURATION_MODE_Pos)        /* Bus voltage, triggered*/
#define INA219_CONFIGURATION_MODE_MODE011 ((3u) << INA219_CONFIGURATION_MODE_Pos)        /* Shunt and bus, triggered*/
#define INA219_CONFIGURATION_MODE_MODE100 ((4u) << INA219_CONFIGURATION_MODE_Pos)        /* ADC off (disabled)*/
#define INA219_CONFIGURATION_MODE_MODE101 ((5u) << INA219_CONFIGURATION_MODE_Pos)        /* Shunt voltage, continuous*/
#define INA219_CONFIGURATION_MODE_MODE110 ((6u) << INA219_CONFIGURATION_MODE_Pos)        /* Bus voltage, continuous*/
#define INA219_CONFIGURATION_MODE_MODE111 ((7u) << INA219_CONFIGURATION_MODE_Pos)        /* Shunt and bus, continuous*/

/**
 * Definitions for Shunt voltage register
 *
 * Shunt voltage measurement data. 
*/
#define INA219_SHUNT_VOLTAGE_INDEX ((uint8_t)0x01)

/**
 * Definitions for Bus voltage register
 *
 * Bus voltage measurement data. 
*/
#define INA219_BUS_VOLTAGE_INDEX ((uint8_t)0x02)

/*  */
#define INA219_BUS_VOLTAGE_BD_Pos ((uint16_t)3)
#define INA219_BUS_VOLTAGE_BD_Msk (((uint16_t)0x1fff) << INA219_BUS_VOLTAGE_BD_Pos)
#define INA219_BUS_VOLTAGE_BD INA219_BUS_VOLTAGE_BD_Msk

/* Conversion Ready bit (CNVR) indicates when data from a conversion is available in the data output registers */
#define INA219_BUS_VOLTAGE_CNVR_Pos ((uint16_t)1)
#define INA219_BUS_VOLTAGE_CNVR_Msk (((uint16_t)0x0001) << INA219_BUS_VOLTAGE_CNVR_Pos)
#define INA219_BUS_VOLTAGE_CNVR INA219_BUS_VOLTAGE_CNVR_Msk

/* The Math Overflow Flag (OVF) is set when the Power or Current calculations are out of range. */
#define INA219_BUS_VOLTAGE_OVF_Pos ((uint16_t)0)
#define INA219_BUS_VOLTAGE_OVF_Msk (((uint16_t)0x0001) << INA219_BUS_VOLTAGE_OVF_Pos)
#define INA219_BUS_VOLTAGE_OVF INA219_BUS_VOLTAGE_OVF_Msk

/**
 * Definitions for Power register
 *
 * Power measurement data. 
*/
#define INA219_POWER_INDEX ((uint8_t)0x03)

/**
 * Definitions for Current register
 *
 * Contains the value of the current flowing through the shunt resistor. 
*/
#define INA219_CURRENT_INDEX ((uint8_t)0x04)

/**
 * Definitions for Calibration register
 *
 * Gets full-scale range and LSB of Current and power measurements. Overall 
 * system calibration. 
*/
#define INA219_CALIBRATION_INDEX ((uint8_t)0x05)

#endif