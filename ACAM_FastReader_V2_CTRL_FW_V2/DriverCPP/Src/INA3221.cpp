/*
 * TMP275.cpp
 *
 *  Created on: Aug 13, 2020
 *      Author: User
 */



#include "../Inc/INA3221.h"

bool INA3221Driver::Initialize(void *arg)
{
	return true;
}


bool INA3221Driver::UnInitialize()
{
	return true;
}
/*
 * cmd: required channel
 * VOLTAGE_TEC=0,CURRENT_TEC,VOLTAGE_12V,CURRENT_12V,VOLTAGE_7V,CURRENT_7V,VOLTAGE_3V3,CURRENT_3V3

 */

uint16_t INA3221Driver::IOCtl(IOCtlCommand cmd,uint8_t *data, uint16_t *size,void *cmdarg)
{
	if(cmd == IOCTL_READ)
	{
		double temp;
		uint8_t channel = *((uint8_t*)cmdarg);
		HAL_StatusTypeDef status;
		uint8_t buffer[2];

		if(INA3221_I2C_READ((this->address)<<1, channel, I2C_MEMADD_SIZE_8BIT, buffer, 2) != I2C_OK)
		{
			LOG(LOG_ERROR,"INA3221 I2C_READ failed !")
			return DRIVER_ERROR;
		}

		switch(channel)
		{
		case VOLTAGE_TEC:
			status=INA3221_I2C_READ((this->address)<<1, INA3221_BUSV_CH1, I2C_MEMADD_SIZE_8BIT, buffer, 2);
			temp=(double)this->buffer2double(buffer,VOLTAGE_COEFF);
			break;

		case CURRENT_TEC:
			status=INA3221_I2C_READ((this->address)<<1, INA3221_SHUNTV_CH1, I2C_MEMADD_SIZE_8BIT, buffer, 2);
			temp=(double)this->buffer2double(buffer,CURRENT_COEFF)/RESISTOR_TEC;
			break;

		case VOLTAGE_12V:
			status=INA3221_I2C_READ((this->address)<<1, INA3221_BUSV_CH2, I2C_MEMADD_SIZE_8BIT, buffer, 2);
			temp=(double)this->buffer2double(buffer,VOLTAGE_COEFF);
			break;

		case CURRENT_12V:
			status=INA3221_I2C_READ((this->address)<<1, INA3221_SHUNTV_CH2, I2C_MEMADD_SIZE_8BIT, buffer, 2);
			temp=(double)this->buffer2double(buffer,CURRENT_COEFF)/RESISTOR_12V;
			break;

		case VOLTAGE_7V:
			status=INA3221_I2C_READ((this->address)<<1, INA3221_BUSV_CH1, I2C_MEMADD_SIZE_8BIT, buffer, 2);
			temp=(double)this->buffer2double(buffer,VOLTAGE_COEFF);
			break;

		case CURRENT_7V:
			status=INA3221_I2C_READ((this->address)<<1, INA3221_SHUNTV_CH1, I2C_MEMADD_SIZE_8BIT, buffer, 2);
			temp=(double)this->buffer2double(buffer,CURRENT_COEFF)/RESISTOR_7V;
			break;

		case VOLTAGE_3V3:
			status=INA3221_I2C_READ((this->address)<<1, INA3221_BUSV_CH3, I2C_MEMADD_SIZE_8BIT, buffer, 2);
			temp=(double)this->buffer2double(buffer,VOLTAGE_COEFF);
			break;

		case CURRENT_3V3:
			status=INA3221_I2C_READ((this->address)<<1, INA3221_SHUNTV_CH3, I2C_MEMADD_SIZE_8BIT, buffer, 2);
			temp=(double)this->buffer2double(buffer,CURRENT_COEFF)/RESISTOR_3V3;
			break;
		}

		if(status!=INA3221_I2C_OK)
		{
				LOG(LOG_ERROR,"INA3221 I2C_READ failed !")
				return DRIVER_ERROR;
		}

		memcpy(data, &temp, sizeof(temp));
		*size = sizeof(temp);
	}

	return DRIVER_OK;
}

double INA3221Driver::buffer2double(uint8_t *buffer,double coeff)
{
	double value_d;
	uint16_t value=(uint16_t) (buffer[0]<<8)|(uint16_t)(buffer[1]<<0);
	if(value &0x8000)
	{
		value=value&0x7FFF;
		value=(uint16_t)value-1;
		value=(uint16_t)~value;
		value=(uint16_t)value>>3;
		value_d=(double)value*-1.0*coeff;
	}
	else
	{
		value=(uint16_t)value>>3;
		value_d=(double)value*coeff;
	}
	return value_d;
}
