/*
 * TaskLED.cpp
 *
 *  Created on: Jan 7, 2021
 *      Author: User
 */


#include "../Inc/TaskLED.h"


void TaskLED::RunLoop(pTaskArgs arg)
{
   while(arg->run)
   {
	   IDriver *drv = arg->driver->GetByName("TEMP");
   }
}

