/*
 * TaskDayNight.h
 *
 *  Created on: Jan 7, 2021
 *      Author: User
 */

#ifndef INC_TASKDAYNIGHT_H_
#define INC_TASKDAYNIGHT_H_

#include "ITask.h"
#include "TaskArgs.h"

class TaskDayNight : public ITask<pTaskArgs>
{
public:
	virtual void RunLoop(pTaskArgs arg);
};


#endif /* INC_TASKDAYNIGHT_H_ */
