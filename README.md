# IMU initialisation
The followin registers are used during the initialisation phase of the IMU.

| Register (Hex)| Note|
| :--- | :--- |
| PWR_MGMT_1    (0x6B)        | Set clock source and wakes up IMU|
|  WHO_AM_I     (0x75)        | Check if I2C is configured properly|
|  CONFIG       (0x1A)        | Set lowpassfilter and bandwidth|
|  SMPLRT_DIV   (0x19)        | Sets samplerate|
|  GYRO_CONFIG  (0x1B)        |Configures Gyro full range|
|  ACCEL_CONFIG (0x1C)        |Configures Gyro full range|
|  INT_PIN_CFG  (0x37)        |Configures behaviour of interrupt signal at the INT pin|
|  INT_ENABLE   (0x38)           |Enables interrupt|

