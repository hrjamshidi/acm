/*
 * TaskDoorOpen.h
 *
 *  Created on: Jan 7, 2021
 *      Author: User
 */

#ifndef INC_TASKDOOROPEN_H_
#define INC_TASKDOOROPEN_H_


#include "ITask.h"
#include "TaskArgs.h"

class TaskDoorOpen : public ITask<pTaskArgs>
{
public:
	virtual void RunLoop(pTaskArgs arg);
};


#endif /* INC_TASKDOOROPEN_H_ */
