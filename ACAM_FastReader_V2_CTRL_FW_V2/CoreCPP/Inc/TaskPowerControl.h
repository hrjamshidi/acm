/*
 * PowerControl.h
 *
 *  Created on: Jan 7, 2021
 *      Author: User
 */

#ifndef INC_TASKPOWERCONTROL_H_
#define INC_TASKPOWERCONTROL_H_


#include "ITask.h"
#include "TaskArgs.h"

class TaskPowerControl : public ITask<pTaskArgs>
{
public:
	virtual void RunLoop(pTaskArgs arg);
};


#endif /* INC_TASKPOWERCONTROL_H_ */
