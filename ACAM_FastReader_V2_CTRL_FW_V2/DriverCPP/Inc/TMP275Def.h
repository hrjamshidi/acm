/*
 * TMP275Def.h
 *
 *  Created on: Aug 13, 2020
 *      Author: User
 */

#ifndef INC_TMP275DEF_H_
#define INC_TMP275DEF_H_

#include "stm32f4xx_hal.h"
#include "cmsis_os.h"

extern I2C_HandleTypeDef hi2c3;

#define I2C_DELAY  1000

#define I2C_OK     HAL_OK
#define I2C_ERROR  !HAL_OK

#define TMP275_DELAY osDelay

#define I2C_WRITE(address,buffer,size)   HAL_I2C_Master_Transmit(&hi2c3,address,buffer,size,I2C_DELAY)
#define I2C_READ(address,buffer,size)    HAL_I2C_Master_Receive(&hi2c3,address,buffer,size,I2C_DELAY)


#endif /* INC_TMP275DEF_H_ */
