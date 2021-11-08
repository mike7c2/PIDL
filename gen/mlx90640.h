/**
 * Automatically generated code by pidl
 * Definition generated using:
 *     https://www.melexis.com/en/documents/documentation/datasheets/datasheet-mlx90640
 *     MLX90640 32x24 IR array
 *     SREVISION 12 – DECEMBER 3, 2019
 */
/**
 * This is a set of register definitions for MLX90640
 *
 * The MLX90640 is a fully calibrated 32x24 pixels thermal IR array in an 
 * industry standard 4-lead TO39 package with digital interface. The MLX90640 
 * contains 768 FIR pixels. An ambient sensor is integrated to measure the 
 * ambient temperature of the chip and supply sensor to measure the VDD. The 
 * outputs of all sensors IR, Ta and VDD are stored in internal RAM and are 
 * accessible through I2C. */
#ifndef MLX90640_H
#define MLX90640_H

/**
 * Definitions for STATUS register
 *
 * Temperature register 
*/
#define MLX90640_STATUS_INDEX ((uint16_t)0x8000)

/* Enable RAM overwrite */
#define MLX90640_STATUS_EN_OV_Pos (4u)
#define MLX90640_STATUS_EN_OV_Msk ((0x1u) << MLX90640_STATUS_EN_OV_Pos)
#define MLX90640_STATUS_EN_OV MLX90640_STATUS_EN_OV_Msk

/* New data available in RAM */
#define MLX90640_STATUS_DATA_READY_Pos (3u)
#define MLX90640_STATUS_DATA_READY_Msk ((0x1u) << MLX90640_STATUS_DATA_READY_Pos)
#define MLX90640_STATUS_DATA_READY MLX90640_STATUS_DATA_READY_Msk

/* Last measured subpage */
#define MLX90640_STATUS_LAST_SUBPAGE_Pos (0u)
#define MLX90640_STATUS_LAST_SUBPAGE_Msk ((0x4u) << MLX90640_STATUS_LAST_SUBPAGE_Pos)
#define MLX90640_STATUS_LAST_SUBPAGE MLX90640_STATUS_LAST_SUBPAGE_Msk
#define MLX90640_STATUS_LAST_SUBPAGE_SUBPAGE0 ((0u) << MLX90640_STATUS_LAST_SUBPAGE_Pos)        /* Subpage 0 selected*/
#define MLX90640_STATUS_LAST_SUBPAGE_SUBPAGE1 ((1u) << MLX90640_STATUS_LAST_SUBPAGE_Pos)        /* Subpage 1 selected*/

/**
 * Definitions for CONTROL register
 *
 * Configuration Register 
*/
#define MLX90640_CONTROL_INDEX ((uint16_t)0x800d)

/* Pattern for reading data from sensor */
#define MLX90640_CONTROL_READING_PATTERN_Pos (12u)
#define MLX90640_CONTROL_READING_PATTERN_Msk ((0x1u) << MLX90640_CONTROL_READING_PATTERN_Pos)
#define MLX90640_CONTROL_READING_PATTERN MLX90640_CONTROL_READING_PATTERN_Msk
#define MLX90640_CONTROL_READING_PATTERN_INTERLEAVED ((0u) << MLX90640_CONTROL_READING_PATTERN_Pos)        /* Interleaved read pattern*/
#define MLX90640_CONTROL_READING_PATTERN_CHESS ((1u) << MLX90640_CONTROL_READING_PATTERN_Pos)        /* Chess read pattern*/

/*  */
#define MLX90640_CONTROL_RESOLUTION_CONTROL_Pos (10u)
#define MLX90640_CONTROL_RESOLUTION_CONTROL_Msk ((0x2u) << MLX90640_CONTROL_RESOLUTION_CONTROL_Pos)
#define MLX90640_CONTROL_RESOLUTION_CONTROL MLX90640_CONTROL_RESOLUTION_CONTROL_Msk
#define MLX90640_CONTROL_RESOLUTION_CONTROL_16BIT ((0u) << MLX90640_CONTROL_RESOLUTION_CONTROL_Pos)        /* 16BIT ADC resolution*/
#define MLX90640_CONTROL_RESOLUTION_CONTROL_17BIT ((1u) << MLX90640_CONTROL_RESOLUTION_CONTROL_Pos)        /* 17BIT ADC resolution*/
#define MLX90640_CONTROL_RESOLUTION_CONTROL_18BIT ((2u) << MLX90640_CONTROL_RESOLUTION_CONTROL_Pos)        /* 18BIT ADC resolution*/
#define MLX90640_CONTROL_RESOLUTION_CONTROL_19BIT ((3u) << MLX90640_CONTROL_RESOLUTION_CONTROL_Pos)        /* 19BIT ADC resolution*/

/* Control refresh rate of IR sensor */
#define MLX90640_CONTROL_REFRESH_RATE_Pos (7u)
#define MLX90640_CONTROL_REFRESH_RATE_Msk ((0x4u) << MLX90640_CONTROL_REFRESH_RATE_Pos)
#define MLX90640_CONTROL_REFRESH_RATE MLX90640_CONTROL_REFRESH_RATE_Msk
#define MLX90640_CONTROL_REFRESH_RATE_HZ5 ((0u) << MLX90640_CONTROL_REFRESH_RATE_Pos)        /* 0.5Hz*/
#define MLX90640_CONTROL_REFRESH_RATE_1HZ ((1u) << MLX90640_CONTROL_REFRESH_RATE_Pos)        /* 1Hz*/
#define MLX90640_CONTROL_REFRESH_RATE_2HZ ((2u) << MLX90640_CONTROL_REFRESH_RATE_Pos)        /* 2Hz*/
#define MLX90640_CONTROL_REFRESH_RATE_4HZ ((3u) << MLX90640_CONTROL_REFRESH_RATE_Pos)        /* 4Hz*/
#define MLX90640_CONTROL_REFRESH_RATE_8HZ ((4u) << MLX90640_CONTROL_REFRESH_RATE_Pos)        /* 8Hz*/
#define MLX90640_CONTROL_REFRESH_RATE_16HZ ((5u) << MLX90640_CONTROL_REFRESH_RATE_Pos)        /* 16Hz*/
#define MLX90640_CONTROL_REFRESH_RATE_32HZ ((6u) << MLX90640_CONTROL_REFRESH_RATE_Pos)        /* 32Hz*/
#define MLX90640_CONTROL_REFRESH_RATE_64HZ ((7u) << MLX90640_CONTROL_REFRESH_RATE_Pos)        /* 64Hz*/

/*  */
#define MLX90640_CONTROL_SEL_SUBPAGE_Pos (4u)
#define MLX90640_CONTROL_SEL_SUBPAGE_Msk ((0x4u) << MLX90640_CONTROL_SEL_SUBPAGE_Pos)
#define MLX90640_CONTROL_SEL_SUBPAGE MLX90640_CONTROL_SEL_SUBPAGE_Msk
#define MLX90640_CONTROL_SEL_SUBPAGE_SUBPAGE0 ((0u) << MLX90640_CONTROL_SEL_SUBPAGE_Pos)        /* Subpage 0 selected*/
#define MLX90640_CONTROL_SEL_SUBPAGE_SUBPAGE1 ((1u) << MLX90640_CONTROL_SEL_SUBPAGE_Pos)        /* Subpage 1 selected*/

/*  */
#define MLX90640_CONTROL_EN_REPEAT_Pos (3u)
#define MLX90640_CONTROL_EN_REPEAT_Msk ((0x1u) << MLX90640_CONTROL_EN_REPEAT_Pos)
#define MLX90640_CONTROL_EN_REPEAT MLX90640_CONTROL_EN_REPEAT_Msk
#define MLX90640_CONTROL_EN_REPEAT_TOGGLE ((0u) << MLX90640_CONTROL_EN_REPEAT_Pos)        /* Toggles between subpage "0" and subpage "1" if Enable subpages mode = "1"*/
#define MLX90640_CONTROL_EN_REPEAT_SELECT ((1u) << MLX90640_CONTROL_EN_REPEAT_Pos)        /* Select subpage determines which subpage to be measured if Enable subpages mode = "1"*/

/*  */
#define MLX90640_CONTROL_EN_HOLD_Pos (2u)
#define MLX90640_CONTROL_EN_HOLD_Msk ((0x1u) << MLX90640_CONTROL_EN_HOLD_Pos)
#define MLX90640_CONTROL_EN_HOLD MLX90640_CONTROL_EN_HOLD_Msk
#define MLX90640_CONTROL_EN_HOLD_NOHOLD ((0u) << MLX90640_CONTROL_EN_HOLD_Pos)        /* Transfer the data into storage RAM at each measured frame (*/
#define MLX90640_CONTROL_EN_HOLD_HOLD ((1u) << MLX90640_CONTROL_EN_HOLD_Pos)        /* Transfer the data into storage RAM only if en_overwrite = 1*/

/*  */
#define MLX90640_CONTROL_EN_SUBPAGE_Pos (0u)
#define MLX90640_CONTROL_EN_SUBPAGE_Msk ((0x1u) << MLX90640_CONTROL_EN_SUBPAGE_Pos)
#define MLX90640_CONTROL_EN_SUBPAGE MLX90640_CONTROL_EN_SUBPAGE_Msk
#define MLX90640_CONTROL_EN_SUBPAGE_SINGLE ((0u) << MLX90640_CONTROL_EN_SUBPAGE_Pos)        /* No subpages, only one page will be measured*/
#define MLX90640_CONTROL_EN_SUBPAGE_ACTIVE ((1u) << MLX90640_CONTROL_EN_SUBPAGE_Pos)        /* Subpage mode is activated*/

/**
 * Definitions for I2C_CONFIGURATION register
 *
 * Configuration Register for I2C 
*/
#define MLX90640_I2C_CONFIGURATION_INDEX ((uint16_t)0x800f)

/*  */
#define MLX90640_I2C_CONFIGURATION_DRIVER_LIMIT_Pos (2u)
#define MLX90640_I2C_CONFIGURATION_DRIVER_LIMIT_Msk ((0x1u) << MLX90640_I2C_CONFIGURATION_DRIVER_LIMIT_Pos)
#define MLX90640_I2C_CONFIGURATION_DRIVER_LIMIT MLX90640_I2C_CONFIGURATION_DRIVER_LIMIT_Msk
#define MLX90640_I2C_CONFIGURATION_DRIVER_LIMIT_ON ((0u) << MLX90640_I2C_CONFIGURATION_DRIVER_LIMIT_Pos)        /* SDA driver current limit is ON*/
#define MLX90640_I2C_CONFIGURATION_DRIVER_LIMIT_OFF ((1u) << MLX90640_I2C_CONFIGURATION_DRIVER_LIMIT_Pos)        /* SDA driver current limit is OFF*/

/*  */
#define MLX90640_I2C_CONFIGURATION_THRESHOLD_Pos (1u)
#define MLX90640_I2C_CONFIGURATION_THRESHOLD_Msk ((0x1u) << MLX90640_I2C_CONFIGURATION_THRESHOLD_Pos)
#define MLX90640_I2C_CONFIGURATION_THRESHOLD MLX90640_I2C_CONFIGURATION_THRESHOLD_Msk
#define MLX90640_I2C_CONFIGURATION_THRESHOLD_VDD ((0u) << MLX90640_I2C_CONFIGURATION_THRESHOLD_Pos)        /* VDD reffered threshold (normal mode)*/
#define MLX90640_I2C_CONFIGURATION_THRESHOLD_1V8 ((1u) << MLX90640_I2C_CONFIGURATION_THRESHOLD_Pos)        /* 1.8V reffered threshold (1.8V mode)*/

/*  */
#define MLX90640_I2C_CONFIGURATION_FM_Pos (0u)
#define MLX90640_I2C_CONFIGURATION_FM_Msk ((0x1u) << MLX90640_I2C_CONFIGURATION_FM_Pos)
#define MLX90640_I2C_CONFIGURATION_FM MLX90640_I2C_CONFIGURATION_FM_Msk
#define MLX90640_I2C_CONFIGURATION_FM_ENABLE ((0u) << MLX90640_I2C_CONFIGURATION_FM_Pos)        /* FM+ mode enabled*/
#define MLX90640_I2C_CONFIGURATION_FM_DISABLE ((1u) << MLX90640_I2C_CONFIGURATION_FM_Pos)        /* FM+ mode disabled*/

/*  *  */
#define MLX90640_ROM_Offset ((uint16_t)0x0000)
#define MLX90640_ROM_Size ((uint16_t)0x0400)

/*  *  */
#define MLX90640_RAM_Offset ((uint16_t)0x0400)
#define MLX90640_RAM_Size ((uint16_t)0x0400)

/*  *  */
#define MLX90640_PIXEL_RAM_Offset ((uint16_t)0x0400)
#define MLX90640_PIXEL_RAM_Size ((uint16_t)0x0300)

/*  *  */
#define MLX90640_EEPROM_Offset ((uint16_t)0x2400)
#define MLX90640_EEPROM_Size ((uint16_t)0x0340)

/*  *  */
#define MLX90640_REGISTERS_RESERVED_Offset ((uint16_t)0x8000)
#define MLX90640_REGISTERS_RESERVED_Size ((uint16_t)0x000c)

/*  *  */
#define MLX90640_REGISTERS_Offset ((uint16_t)0x800d)
#define MLX90640_REGISTERS_Size ((uint16_t)0x0002)

/*  *  */
#define MLX90640_REGISTERS_RESERVED_2_Offset ((uint16_t)0x8011)
#define MLX90640_REGISTERS_RESERVED_2_Size ((uint16_t)0x0005)

#endif