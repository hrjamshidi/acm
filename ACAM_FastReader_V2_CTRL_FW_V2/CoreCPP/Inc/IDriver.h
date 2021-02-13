/*
 * IDriver.h
 *
 *  Created on: Aug 13, 2020
 *      Author: User
 */

#ifndef INC_IDRIVER_H_
#define INC_IDRIVER_H_

#include <stdint.h>
#include <stddef.h>

#include "Object.h"
#include "IEvent.h"
#include "Error.h"

#include "ILogger.h"


#define DRIVER_OK       0
#define DRIVER_ERROR    1

#define DRIVER_EC_NO    0


enum IOCtlCommand
{
	IOCTL_RESET,
	IOCTL_READ,
	IOCTL_WRITE

};


enum DriverStatus
{
	DS_NotLoaded,
	DS_Initializing,
	DS_Run,
	DS_Error
};

typedef uint32_t DriverErrorCode;

class IDriver : public Object
{

protected:

	DEFINE_EVENT(Error,Error)
	DEFINE_LOGGER

	DriverErrorCode errorCode;
	DriverStatus    status;

	virtual void SetStatus(DriverStatus ds)
	{
		this->status = ds;
	}

	virtual void SetErrorCode(DriverErrorCode dec)
	{
		this->errorCode = dec;
	}


public:

	IDriver(ILogger *log)
	{
		ASSIGN_LOGGER(log)
	    errorCode = DRIVER_EC_NO;
		status = DS_NotLoaded;
	}

	virtual bool Initialize(void *args = NULL) = 0;

	virtual bool UnInitialize() = 0;

	virtual DriverStatus GetStatus() { return this->status; }
	virtual DriverErrorCode GetErrorCode() { return this->errorCode; }


	virtual uint16_t IOCtl(IOCtlCommand cmd,uint8_t *data, uint16_t *size,void *cmdarg) = 0;

	IMPLEMENT_EVENT(Error,Error)
};



#endif /* INC_IDRIVER_H_ */
