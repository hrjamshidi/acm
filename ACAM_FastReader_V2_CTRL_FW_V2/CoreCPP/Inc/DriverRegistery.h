/*
 * DriverRegistery.h
 *
 *  Created on: Jan 7, 2021
 *      Author: User
 */

#ifndef INC_DRIVERREGISTERY_H_
#define INC_DRIVERREGISTERY_H_

#include "Object.h"
#include "IEvent.h"
#include "IDriver.h"
#include <cstring>

#define MAX_DRIVER_ENTRY 10
#define MAX_DRIVER_NAME  8


class DriverRegistery : public Object
{
protected:
	char *driverName[MAX_DRIVER_ENTRY][MAX_DRIVER_NAME];
	IDriver *drivers[MAX_DRIVER_ENTRY];
	uint8_t  driverCount;

	uint8_t Find(const char *name)
	{
	     uint8_t rv = 255;

	     for(uint8_t i=0;i<MAX_DRIVER_ENTRY;i++)
	     {
	    	 if(strcmp((char*)driverName[i], name) == 0)
	    	 {
	    		 rv = i;
	    		 break;
	    	 }
	     }

	     return rv;
	}

public:
	DriverRegistery()
	{
		Reset();
		driverCount = 0;
	}

	virtual ~DriverRegistery()
	{

	}

	bool Register(const char* name, IDriver *driver)
	{
		if(driverCount < MAX_DRIVER_ENTRY)
		{
			memcpy((void*)driverName[driverCount], (void*)name, MAX_DRIVER_NAME-1);
			drivers[driverCount] = driver;
			driverCount++;
		}
		else
		{
			return false;
		}
	}


	void Unregister(const char *name)
	{

		uint8_t index = Find(name);

		if(index < MAX_DRIVER_ENTRY)
		{
			drivers[index] = NULL;
			memset((void*)driverName[index],0,MAX_DRIVER_NAME);
			driverCount--;
		}

	}

	IDriver *GetByName(const char *name)
	{
		uint8_t index = Find(name);

		if(index < MAX_DRIVER_ENTRY)
		{
			return drivers[index];
		}

		return NULL;
	}


	void Reset()
	{
		memset((void*)driverName,0,MAX_DRIVER_NAME * MAX_DRIVER_ENTRY);
		memset((void*)drivers,0,MAX_DRIVER_ENTRY);
	}



};


#endif /* INC_DRIVERREGISTERY_H_ */
