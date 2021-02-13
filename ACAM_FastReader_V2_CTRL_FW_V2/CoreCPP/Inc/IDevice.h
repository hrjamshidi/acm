/*
 * IDevice.h
 *
 *  Created on: Jul 23, 2020
 *      Author: User
 */

#ifndef INC_IDEVICE_H_
#define INC_IDEVICE_H_

#include <stddef.h>
#include <stdint.h>
#include "HWFrame.h"
#include "Object.h"

class IDevice : public Object
{
public:
	virtual bool SendFrame(const HWFrame* frame) = 0;
	virtual HWFrame* RecieveFrame() = 0;
};



#endif /* INC_IDEVICE_H_ */
