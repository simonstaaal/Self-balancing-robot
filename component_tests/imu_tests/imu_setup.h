#include "imu_regs.h"
#include "imu_const.h"
#include "pico/stdlib.h"
#include "hardware/i2c.h" 

/**
 * @brief Helper function to write to IMU using I2C
 * 
 * @param reg Register to write to
 * @param val Value to be written to register
 * @return true Sucessfull write
 * @return false Unsuccessfull write
 */
bool imu_write(uint8_t reg, uint8_t val);

/**
 * @brief Helper function to read from IMU usin I2C
 * 
 * @param reg Register to read from
 * @param buffer Buffer for storing data, needs to be atleast the same size as length
 * @param length number of bytes to store 
 * @return true Sucessful read
 * @return false Unsuccessfull read
 */
bool imu_read(uint8_t reg, uint8_t *buffer, uint8_t length);


