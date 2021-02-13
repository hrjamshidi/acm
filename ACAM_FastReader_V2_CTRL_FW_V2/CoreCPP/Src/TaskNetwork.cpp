/*
 * TaskNetwork.cpp
 *
 *  Created on: Jan 7, 2021
 *      Author: User
 */


#include "../Inc/TaskNetwork.h"
#include "../Inc/TCPServer.h"


void TaskNetwork::RunLoop(pTaskArgs arg)
{
   TCPServer *server = new TCPServer();


   while(arg->run)
   {
	   IDriver *drv = arg->driver->GetByName("TEMP");
   }
}

