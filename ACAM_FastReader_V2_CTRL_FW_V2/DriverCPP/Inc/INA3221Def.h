/*
 * TMP275Def.h
 *
 *  Created on: Aug 13, 2020
 *      Author: User
 */

#ifndef INC_INA3221DEF_H_
#define INC_INA3221DEF_H_

#include "stm32f4xx_hal.h"
#include "cmsis_os.h"

extern I2C_HandleTypeDef hi2c3;

#define INA3221_I2C_DELAY  1000

#define INA3221_I2C_OK     HAL_OK
#define INA3221_I2C_ERROR  !HAL_OK

#define INA3221_DELAY osDelay

#define INA3221_I2C_WRITE(address,dev_address,adrsize,buffer,size)   HAL_I2C_Mem_Write(&hi2c3,address,dev_address,adrsize,buffer,size,INA3221_I2C_DELAY)
#define INA3221_I2C_READ(address,dev_address,adrsize,buffer,size)    HAL_I2C_Mem_Read(&hi2c3,address,dev_address,adrsize,buffer,size,INA3221_I2C_DELAY)


#endif /* INC_TMP275DEF_H_ */
