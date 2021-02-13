/*
 * TaskUART.cpp
 *
 *  Created on: Jan 7, 2021
 *      Author: User
 */


#include "../Inc/TaskUART.h"

void TaskUART::RunLoop(pTaskArgs arg)
{
   while(arg->run)
   {
	   IDriver *drv = arg->driver->GetByName("TEMP");
   }
}
