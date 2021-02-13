/*
 * TMP275.cpp
 *
 *  Created on: Aug 13, 2020
 *      Author: User
 */



#include "../Inc/TMP275.h"

bool TMP275Driver::Initialize(void *arg)
{
	this->resolution = 0;

	return  //this->SetResolution(TMP_CH0, TMP275_12BIT) &&
			//this->SetResolution(TMP_CH1, TMP275_12BIT) &&
			//this->SetResolution(TMP_CH2, TMP275_12BIT) &&
			//this->SetResolution(TMP_CH3, TMP275_12BIT) &&
			this->SetResolution(TMP_CH4, TMP275_12BIT);// &&
			//this->SetResolution(TMP_CH5, TMP275_12BIT) &&
			//this->SetResolution(TMP_CH6, TMP275_12BIT) &&
			//this->SetResolution(TMP_CH7, TMP275_12BIT);
}


bool TMP275Driver::UnInitialize()
{
	return true;
}


uint16_t TMP275Driver::IOCtl(IOCtlCommand cmd,uint8_t *data, uint16_t *size,void *cmdarg)
{

	if(cmd == IOCTL_READ)
	{
		uint8_t channel = *((uint8_t*)cmdarg);
		uint8_t buffer[2] = { TMP275_TMP_REG, 0};
		uint16_t raw_temp;
		double temp = 0;

		if(I2C_WRITE((TMP275_BASEADDRESS+channel)<<1,buffer,1) != I2C_OK)
		{
			return DRIVER_ERROR;
		}

		switch(this->resolution)
		{
		  case TMP275_9BIT:  TMP275_DELAY(TMP275_9BIT_DELAY);  break;
		  case TMP275_10BIT: TMP275_DELAY(TMP275_10BIT_DELAY); break;
		  case TMP275_11BIT: TMP275_DELAY(TMP275_11BIT_DELAY); break;
		  case TMP275_12BIT: TMP275_DELAY(TMP275_12BIT_DELAY); break;
		}

		if(I2C_READ((TMP275_BASEADDRESS+channel)<<1,buffer,2) != I2C_OK)
		{
			return DRIVER_ERROR;
		}

		raw_temp=(buffer[0]<<4)|(buffer[1]>>4);
		if(buffer[0]>128)
		{
			temp=((double)raw_temp-(double)0x1000)/16.0;
		}
		else
		{
			temp=(double)raw_temp/16.0;

		}

		memcpy(data, &temp, sizeof(temp));
		*size = sizeof(temp);

	}

	return DRIVER_OK;
}


bool TMP275Driver::SetResolution(uint8_t channel, uint8_t res)
{
	uint8_t buffer[]={TMP275_CONF_REG,res};

	if(I2C_WRITE((TMP275_BASEADDRESS + channel) << 1, buffer, 2) == I2C_OK)
	{
	   this->resolution = res;
	   return true;
	}

	LOG(LOG_ERROR,"SetResolution I2C_WRITE is failed !")

	return false;
}
