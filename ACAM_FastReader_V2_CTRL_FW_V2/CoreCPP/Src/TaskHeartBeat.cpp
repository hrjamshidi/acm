/*
 * TaskHeartBeat.cpp
 *
 *  Created on: Jan 7, 2021
 *      Author: User
 */



#include "../Inc/TaskHeartBeat.h"


void TaskHeartBeat::RunLoop(pTaskArgs arg)
{
   while(arg->run)
   {
	   IDriver *drv = arg->driver->GetByName("TEMP");
	   drv->GetErrorCode();
   }
}
