/*
 * TaskDayNight.cpp
 *
 *  Created on: Jan 7, 2021
 *      Author: User
 */


#include "../Inc/TaskDayNight.h"


void TaskDayNight::RunLoop(pTaskArgs arg)
{
   while(arg->run)
   {
	   IDriver *drv = arg->driver->GetByName("TEMP");
   }
}

