/*
 * IFrameCompleted.h
 *
 *  Created on: Jul 23, 2020
 *      Author: User
 */

#ifndef INC_IFRAMECOMPLETED_H_
#define INC_IFRAMECOMPLETED_H_


#include "HWFrame.h"

#include "Object.h"

class IFrameCompleted : public Object
{
public:
	virtual void  NewFrame(Object* pr, HWFrame* frame) = 0;
};




#endif /* INC_IFRAMECOMPLETED_H_ */
