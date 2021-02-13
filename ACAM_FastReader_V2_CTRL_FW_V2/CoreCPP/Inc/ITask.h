/*
 * ITask.h
 *
 *  Created on: Jan 7, 2021
 *      Author: User
 */

#ifndef INC_ITASK_H_
#define INC_ITASK_H_

#include "Object.h"

template <class T>
class ITask : public Object
{
public:
	virtual void RunLoop(T obj) = 0;
};


#endif /* INC_ITASK_H_ */
