#include "imu_regs.h"

#define DLPF_CFG0 (0x00 << 3)
#define DLPF_CFG1 (0x01 << 3)
#define DLPF_CFG2 (0x02 << 3)
#define DLPF_CFG3 (0x03 << 3)
#define DLPF_CFG4 (0x04 << 3)
#define DLPF_CFG5 (0x05 << 3)
#define DLPF_CFG6 (0x06 << 3)
#define DLPF_CFG7 (0x07 << 3)

#define SMPLRT_DIV_VAL 0x04

#define FS_SEL0 (0x00 << 2)
#define FS_SEL1 (0x01 << 2)
#define FS_SEL2 (0x02 << 2)
#define FS_SEL3 (0x03 << 2)

#define AFS_SEL0 (0x00 << 2)
#define AFS_SEL1 (0x01 << 2)
#define AFS_SEL2 (0x02 << 2)
#define AFS_SEL3 (0x03 << 2)


#define DEVICE_RESET 0x80
#define DEVICE_WAKE_SET_CLK 0x01
#define DATA_READY_EN 0x01
#define PIN_CONFIG 0x10
