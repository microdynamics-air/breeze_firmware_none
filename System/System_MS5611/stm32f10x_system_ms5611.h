#ifndef __STM32F10X_SYSTEM_MS5611_H__
#define __STM32F10X_SYSTEM_MS5611_H__

#include "stm32f10x.h"

/*addresses of the device CSB = 0*/
#define MS5611_ADDR           0xEE    /*default IIC address*/
#define MS5611_D1             0x40    /*registers of the device*/
#define MS5611_D2             0x50
#define MS5611_RESET          0x1E

#define MS5611_D1D2_SIZE      3       /*D1 and D2 result size(bytes)*/

/*OSR(Over Sampling Ratio)constants*/
#define MS5611_OSR_256        0x00    /*conversion time 0.6ms resolution 0.065mbar*/
#define MS5611_OSR_512        0x02    /*conversion time 1.2ms resolution 0.042mbar*/
#define MS5611_OSR_1024       0x04    /*conversion time 2.3ms resolution 0.027mbar*/
#define MS5611_OSR_2048       0x06    /*conversion time 4.6ms resolution 0.018mbar*/
#define MS5611_OSR_4096       0x08    /*conversion time 9.1ms resolution 0.012mbar*/

/*by adding ints from 0 to 6 we can read all the prom configuration values*/
/*C1 will be at 0xA2 and all the subsequent are multiples of 2*/
#define MS5611_PROM_BASE_ADDR 0xA2
#define MS5611_PROM_REG_COUNT 6       /*number of registers in the prom*/
#define MS5611_PROM_REG_SIZE  2       /*size in bytes of a prom registry*/

#define MSLP                  101325  /*mean Sea Level Pressure = 1013.25 hPA (1hPa = 100Pa = 1mbar)*/

extern volatile float MS5611_Pressure;
extern volatile float MS5611_Altitude;
extern volatile float MS5611_Temperature;
extern uint8_t Baro_Alt_Updated;      /*气压计高度更新完成标志*/
extern uint8_t PaOffsetInited;

extern void MS5611_Init(void);
extern void MS5611_Thread(void);
extern uint8_t WaitBaroInitOffset(void);

#endif
