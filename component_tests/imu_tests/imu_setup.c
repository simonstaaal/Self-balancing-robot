#include "imu_setup.h"

bool imu_write(uint8_t reg, uint8_t val){
    uint8_t buffer[2];

    buffer[0] = reg;
    buffer[1]=val;

    int write_comp = i2c_write_blocking(i2c1,IMU_ADRESS, buffer, sizeof(buffer), false);
    if(write_comp <0){
        return false;
    }
    return true;
}

bool imu_read(uint8_t reg, uint8_t *buffer, uint8_t length){
    uint8_t start_register = reg;

    int write_comp = i2c_write_blocking(i2c1,IMU_ADRESS, &start_register, sizeof(start_register), true);

    if(write_comp < 0){
        return false;
    }

    int read_comp = i2c_read_blocking(i2c1, IMU_ADRESS, buffer, length, false);

    if(read_comp < 0){
        return false;
    }

    return true;
}


/***
- Wakes the IMU from sleepmode
- change the clock source from the default 8Mhz oscillator
- Configures interrupt signal for int pin
- Checks if i2c is working as intended
***/
