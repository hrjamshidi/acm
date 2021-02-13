/*
 * TaskLED.h
 *
 *  Created on: Jan 7, 2021
 *      Author: User
 */

#ifndef INC_TASKLED_H_
#define INC_TASKLED_H_

#include "ITask.h"
#include "TaskArgs.h"

class TaskLED : public ITask<pTaskArgs>
{
public:
	virtual void RunLoop(pTaskArgs arg);
};


#endif /* INC_TASKLED_H_ */
