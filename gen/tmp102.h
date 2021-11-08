/**
 * Automatically generated code by pidl
 * Definition generated using:
 *     hhttps://www.ti.com/lit/ds/symlink/tmp102.pdf
 *     TMP102 Low-Power Digital Temperature Sensor With SMBus and Two-Wire Serial Interface in SOT563
 *     SBOS397H –AUGUST 2007–REVISED DECEMBER 2018
 */
/**
 * This is a set of register definitions for TMP102
 *
 * The TMP102 device is a digital temperature sensor ideal for NTC/PTC 
 * thermistor replacement where high accuracy is required. The device offers an 
 * accuracy of ±0.5°C without requiring calibration or external component signal 
 * conditioning. Device temperature sensors are highly linear and do not require 
 * complex calculations or lookup tables to derive the temperature. The on-chip 
 * 12-bit ADC offers resolutions down to 0.0625°C. The 1.6-mm × 1.6-mm SOT563 
 * package is 68% smaller footprint than an SOT-23 package. The TMP102 device 
 * features SMBus™, two-wire and I2C interface compatibility, and allows up to 
 * four devices on one bus. The device also features an SMBus alert function. 
 * The device is specified to operate over supply voltages from 1.4 to 3.6 V 
 * with the maximum quiescent current of 10 μA over the full operating range. 
 * The TMP102 device is ideal for extended temperature measurement in a variety 
 * of communication, computer, consumer, environmental, industrial, and 
 * instrumentation applications. The device is specified for operation over a 
 * temperature range of –40°C to 125°C.
 */
#ifndef TMP102_H
#define TMP102_H

/**
 * Definitions for Temperature register
 *
 * Temperature register 
*/
#define TMP102_TEMPERATURE_INDEX ((uint8_t)0x00)

/*  */
#define TMP102_TEMPERATURE_TEMP_Pos ((uint16_t)4)
#define TMP102_TEMPERATURE_TEMP_Msk (((uint16_t)0x0fff) << TMP102_TEMPERATURE_TEMP_Pos)
#define TMP102_TEMPERATURE_TEMP TMP102_TEMPERATURE_TEMP_Msk

/**
 * Definitions for Configuration register
 *
 * Configuration Register 
*/
#define TMP102_CONFIGURATION_INDEX ((uint8_t)0x01)

/* When the device is in Shutdown Mode, writing a 1 to the OS bit starts a single temperature conversion. */
#define TMP102_CONFIGURATION_ONE_SHOT_Pos ((uint16_t)15)
#define TMP102_CONFIGURATION_ONE_SHOT_Msk (((uint16_t)0x0001) << TMP102_CONFIGURATION_ONE_SHOT_Pos)
#define TMP102_CONFIGURATION_ONE_SHOT TMP102_CONFIGURATION_ONE_SHOT_Msk

/* The converter resolution bits, R1 and R0, are read-only bits */
#define TMP102_CONFIGURATION_RESOLUTION_Pos ((uint16_t)13)
#define TMP102_CONFIGURATION_RESOLUTION_Msk (((uint16_t)0x0003) << TMP102_CONFIGURATION_RESOLUTION_Pos)
#define TMP102_CONFIGURATION_RESOLUTION TMP102_CONFIGURATION_RESOLUTION_Msk

/* Control number of faults to trigger alarm */
#define TMP102_CONFIGURATION_FAULT_QUEUE_Pos ((uint16_t)11)
#define TMP102_CONFIGURATION_FAULT_QUEUE_Msk (((uint16_t)0x0003) << TMP102_CONFIGURATION_FAULT_QUEUE_Pos)
#define TMP102_CONFIGURATION_FAULT_QUEUE TMP102_CONFIGURATION_FAULT_QUEUE_Msk
#define TMP102_CONFIGURATION_FAULT_QUEUE_1FAULT ((0u) << TMP102_CONFIGURATION_FAULT_QUEUE_Pos)        /* 1 Consecutive fault*/
#define TMP102_CONFIGURATION_FAULT_QUEUE_2FAULT ((1u) << TMP102_CONFIGURATION_FAULT_QUEUE_Pos)        /* 2 Consecutive fault*/
#define TMP102_CONFIGURATION_FAULT_QUEUE_4FAULT ((2u) << TMP102_CONFIGURATION_FAULT_QUEUE_Pos)        /* 4 Consecutive fault*/
#define TMP102_CONFIGURATION_FAULT_QUEUE_6FAULT ((3u) << TMP102_CONFIGURATION_FAULT_QUEUE_Pos)        /* 6 Consecutive fault*/

/* If the POL bit is set to 0 (default), the ALERT pin becomes active low. */
#define TMP102_CONFIGURATION_POLARITY_Pos ((uint16_t)10)
#define TMP102_CONFIGURATION_POLARITY_Msk (((uint16_t)0x0001) << TMP102_CONFIGURATION_POLARITY_Pos)
#define TMP102_CONFIGURATION_POLARITY TMP102_CONFIGURATION_POLARITY_Msk

/* The Thermostat mode bit indicates to the device whether to operate in Comparator mode (TM = 0) or Interrupt (TM = 1). */
#define TMP102_CONFIGURATION_THERMOSTAT_Pos ((uint16_t)9)
#define TMP102_CONFIGURATION_THERMOSTAT_Msk (((uint16_t)0x0001) << TMP102_CONFIGURATION_THERMOSTAT_Pos)
#define TMP102_CONFIGURATION_THERMOSTAT TMP102_CONFIGURATION_THERMOSTAT_Msk

/* Shutdown mode enables when the SD bit is */
#define TMP102_CONFIGURATION_SHUTDOWN_MODE_Pos ((uint16_t)8)
#define TMP102_CONFIGURATION_SHUTDOWN_MODE_Msk (((uint16_t)0x0001) << TMP102_CONFIGURATION_SHUTDOWN_MODE_Pos)
#define TMP102_CONFIGURATION_SHUTDOWN_MODE TMP102_CONFIGURATION_SHUTDOWN_MODE_Msk

/*  */
#define TMP102_CONFIGURATION_CONVERSION_RATE_Pos ((uint16_t)6)
#define TMP102_CONFIGURATION_CONVERSION_RATE_Msk (((uint16_t)0x0003) << TMP102_CONFIGURATION_CONVERSION_RATE_Pos)
#define TMP102_CONFIGURATION_CONVERSION_RATE TMP102_CONFIGURATION_CONVERSION_RATE_Msk
#define TMP102_CONFIGURATION_CONVERSION_RATE_HZ25 ((0u) << TMP102_CONFIGURATION_CONVERSION_RATE_Pos)        /* 0.25 Hz*/
#define TMP102_CONFIGURATION_CONVERSION_RATE_1HZ ((1u) << TMP102_CONFIGURATION_CONVERSION_RATE_Pos)        /* 1 Hz*/
#define TMP102_CONFIGURATION_CONVERSION_RATE_4HZ ((2u) << TMP102_CONFIGURATION_CONVERSION_RATE_Pos)        /* 4 Hz (default)*/
#define TMP102_CONFIGURATION_CONVERSION_RATE_8HZ ((3u) << TMP102_CONFIGURATION_CONVERSION_RATE_Pos)        /* 8 Hz*/

/* Active high alarm bit */
#define TMP102_CONFIGURATION_ALERT_Pos ((uint16_t)5)
#define TMP102_CONFIGURATION_ALERT_Msk (((uint16_t)0x0001) << TMP102_CONFIGURATION_ALERT_Pos)
#define TMP102_CONFIGURATION_ALERT TMP102_CONFIGURATION_ALERT_Msk

/*  */
#define TMP102_CONFIGURATION_EXTENDED_MODE_Pos ((uint16_t)5)
#define TMP102_CONFIGURATION_EXTENDED_MODE_Msk (((uint16_t)0x0001) << TMP102_CONFIGURATION_EXTENDED_MODE_Pos)
#define TMP102_CONFIGURATION_EXTENDED_MODE TMP102_CONFIGURATION_EXTENDED_MODE_Msk
#define TMP102_CONFIGURATION_EXTENDED_MODE_NORMAL_MODE ((0u) << TMP102_CONFIGURATION_EXTENDED_MODE_Pos)        /* */
#define TMP102_CONFIGURATION_EXTENDED_MODE_EXTENDED_MODE ((1u) << TMP102_CONFIGURATION_EXTENDED_MODE_Pos)        /* */

/**
 * Definitions for TLOW register
 *
 * Low temperature register 
*/
#define TMP102_TLOW_INDEX ((uint8_t)0x02)

/*  */
#define TMP102_TLOW_FIELD_Pos ((uint16_t)4)
#define TMP102_TLOW_FIELD_Msk (((uint16_t)0x0fff) << TMP102_TLOW_FIELD_Pos)
#define TMP102_TLOW_FIELD TMP102_TLOW_FIELD_Msk

/**
 * Definitions for THIGH register
 *
 * High temperature register 
*/
#define TMP102_THIGH_INDEX ((uint8_t)0x03)

/*  */
#define TMP102_THIGH_FIELD_Pos ((uint16_t)4)
#define TMP102_THIGH_FIELD_Msk (((uint16_t)0x0fff) << TMP102_THIGH_FIELD_Pos)
#define TMP102_THIGH_FIELD TMP102_THIGH_FIELD_Msk

#endif