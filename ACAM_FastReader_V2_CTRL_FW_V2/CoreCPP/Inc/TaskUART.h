/*
 * TaskUART.h
 *
 *  Created on: Jan 7, 2021
 *      Author: User
 */

#ifndef INC_TASKUART_H_
#define INC_TASKUART_H_

#include "ITask.h"
#include "TaskArgs.h"

class TaskUART : public ITask<pTaskArgs>
{
public:
	virtual void RunLoop(pTaskArgs arg);
};


#endif /* INC_TASKUART_H_ */
