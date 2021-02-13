/*
 * TaskNetwork.h
 *
 *  Created on: Jan 7, 2021
 *      Author: User
 */

#ifndef INC_TASKNETWORK_H_
#define INC_TASKNETWORK_H_



#include "ITask.h"
#include "TaskArgs.h"

class TaskNetwork : public ITask<pTaskArgs>
{
public:
	virtual void RunLoop(pTaskArgs arg);
};


#endif /* INC_TASKNETWORK_H_ */
