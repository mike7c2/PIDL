#include <stdint.h>
#include <stdio.h>

#include "../gen/tmp102.h"

int read_i2c_a8reg16(uint8_t i2c_address, uint8_t offset, uint16_t * result) {
    (void)i2c_address;
    (void)(offset);
    *result = 0;
}
int write_i2c_a8reg16(uint8_t i2c_address, uint8_t offset, uint16_t value) {
    (void)i2c_address;
    (void)offset;
    (void)value;
}

int main(int argc, char* argv[]) {

    /* Read configuration register, update FAULT_QUEUE and CONVERSION_RATE fields */
    uint16_t cfg;
    read_i2c_a8reg16(0x00, TMP102_CONFIGURATION_INDEX, &cfg);
    cfg &= ~(TMP102_CONFIGURATION_FAULT_QUEUE_Msk | TMP102_CONFIGURATION_CONVERSION_RATE_Msk);
    cfg |= TMP102_CONFIGURATION_FAULT_QUEUE_4FAULT | TMP102_CONFIGURATION_CONVERSION_RATE_4HZ;
    write_i2c_a8reg16(0x00, TMP102_CONFIGURATION_INDEX, cfg);

    printf("Running tmp102 test\r\n");
}