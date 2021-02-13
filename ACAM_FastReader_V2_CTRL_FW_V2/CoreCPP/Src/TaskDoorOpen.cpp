/*
 * TaskDoorOpen.cpp
 *
 *  Created on: Jan 7, 2021
 *      Author: User
 */


#include "../Inc/TaskDoorOpen.h"


void TaskDoorOpen::RunLoop(pTaskArgs arg)
{
   while(arg->run)
   {
	   IDriver *drv = arg->driver->GetByName("TEMP");
   }
}

