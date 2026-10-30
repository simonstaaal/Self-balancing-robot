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

bool init_imu(void){
    
    bool reset_imu = imu_write(PWR_MGMT_1, DEVICE_RESET);
    sleep_ms(100);

    uint8_t who = 0;

    bool who_am_i = imu_read(WHO_AM_I, &who, 1) && who == 0x68;
    if(!who_am_i){
        printf("Wrong device or communication error\n");
        return false;  
    }

   bool wakeup_imu = imu_write(PWR_MGMT_1, DEVICE_WAKE_SET_CLK);

   sleep_ms(30);



   if(!reset_imu || !wakeup_imu){
    return false;
   }

   return true;
 
};

bool imu_enable_interrupt(void){

    bool config_int = imu_write(INT_PIN_CFG, PIN_CONFIG);
    bool enable_int = imu_write(INT_ENABLE, DATA_READY_EN);

    if(!config_int || !enable_int){
        return false;
    }

    return true;
}
