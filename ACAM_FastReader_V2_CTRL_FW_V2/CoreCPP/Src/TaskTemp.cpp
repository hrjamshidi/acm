/*
 * TaskTemp.cpp
 *
 *  Created on: Jan 7, 2021
 *      Author: User
 */
#include "../Inc/TaskTemp.h"


void TaskTemp::RunLoop(pTaskArgs arg)
{
   while(arg->run)
   {
	   IDriver *drv = arg->driver->GetByName("TEMP");


   }
}

