/*
 * TaskRTC.h
 *
 *  Created on: Jan 7, 2021
 *      Author: User
 */

#ifndef INC_TASKRTC_H_
#define INC_TASKRTC_H_


#include "ITask.h"
#include "TaskArgs.h"

class TaskRTC : public ITask<pTaskArgs>
{
public:
	virtual void RunLoop(pTaskArgs arg);
};



#endif /* INC_TASKRTC_H_ */
