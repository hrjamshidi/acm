/*
 * TaskHeartBeat.h
 *
 *  Created on: Jan 7, 2021
 *      Author: User
 */

#ifndef INC_TASKHEARTBEAT_H_
#define INC_TASKHEARTBEAT_H_


#include "ITask.h"
#include "TaskArgs.h"

class TaskHeartBeat : public ITask<pTaskArgs>
{
public:
	virtual void RunLoop(pTaskArgs arg);
};


#endif /* INC_TASKHEARTBEAT_H_ */
