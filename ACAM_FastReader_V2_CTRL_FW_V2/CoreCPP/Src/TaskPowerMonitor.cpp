/*
 * TaskPower.cpp
 *
 *  Created on: Jan 7, 2021
 *      Author: User
 */

#include "../Inc/TaskPowerMonitor.h"


void TaskPowerMonitor::RunLoop(pTaskArgs arg)
{
   while(arg->run)
   {
	   IDriver *drv = arg->driver->GetByName("TEMP");
   }
}

