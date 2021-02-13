/*
 * TaskPowerControl.cpp
 *
 *  Created on: Jan 7, 2021
 *      Author: User
 */

#include "../Inc/TaskPowerControl.h"



void TaskPowerControl::RunLoop(pTaskArgs arg)
{
   while(arg->run)
   {
	   IDriver *drv = arg->driver->GetByName("TEMP");
   }
}

