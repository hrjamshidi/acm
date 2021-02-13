/*
 * TaskTemp.h
 *
 *  Created on: Jan 7, 2021
 *      Author: User
 */

#ifndef INC_TASKTEMP_H_
#define INC_TASKTEMP_H_
#include "ITask.h"
#include "TaskArgs.h"

class TaskTemp : public ITask<pTaskArgs>
{
public:
	virtual void RunLoop(pTaskArgs arg);
};


#endif /* INC_TASKTEMP_H_ */
