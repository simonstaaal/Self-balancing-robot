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


/**
 * @brief Wake the IMU from sleppmode and changes clock source. Also controls if I2C is configured properly
 * 
 * @return true Sucessful initialisation
 * @return false Unsuccessful initialisation
 */
bool init_imu(void);


/**
 * @brief Enables interrupt signal on the INT pin
 * 
 * @return true  Enabled interrupt signal was successful
 * @return false Enabled interrupt signal was unsucessful
 */
bool imu_enable_interrupt(void);


/**
 * @brief Configures the lowpass filter and the samplerate
 * 
 * @param lowpass Se docs of MPU 6050
 * @param samplerate Se docs of MPU 6050
 * @return true Successfull configuration 
 * @return false Unsuccesfull configuration
 */
bool config_lowpass_samplerate(uint8_t lowpass, uint8_t samplerate);


/**
 * @brief Configures range of gyroscope and accelerometer
 * 
 * @param gyro_range Sets range of gyroscope
 * @param accel_range Sets range of accelerometer
 * @return true  Successfull configuration
 * @return false Unsuccessfull configuration
 */
bool config_imu_range(uint8_t gyro_range, uint8_t accel_range);