/*
 * TaskPower.h
 *
 *  Created on: Jan 7, 2021
 *      Author: User
 */

#ifndef INC_TASKPOWERMONITOR_H_
#define INC_TASKPOWERMONITOR_H_


#include "ITask.h"
#include "TaskArgs.h"

class TaskPowerMonitor : public ITask<pTaskArgs>
{
public:
	virtual void RunLoop(pTaskArgs arg);
};


#endif /* INC_TASKPOWERMONITOR_H_ */
