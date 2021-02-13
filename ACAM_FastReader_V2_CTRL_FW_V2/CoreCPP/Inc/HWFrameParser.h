/*
 * HWFrameParser.h
 *
 *  Created on: Jul 23, 2020
 *      Author: User
 */

#ifndef INC_HWFRAMEPARSER_H_
#define INC_HWFRAMEPARSER_H_

#include "HWFrame.h"
#include "IFrameCompleted.h"

#include "Object.h"
#include "IEvent.h"
#include <cstring>

class HWFrameParser : public Object
{
protected:
	uint8_t  buffer[MAX_FRAME_SIZE];
	uint16_t index;
	bool     sof;
    bool     len;
    bool     error;
    bool     frameCompleted;
    IEvent<HWFrame> *evtNewFrame;

public:
	HWFrameParser()
	{
		ResetPointer();
		this->evtNewFrame = NULL;
	}

	virtual ~HWFrameParser()
	{

	}

	bool Push(uint8_t data)
	{
	   if(index < (MAX_FRAME_SIZE-1) && !frameCompleted)
	   {
		   if(!sof && data == CC_STX)
		   {
			   buffer[index++] = data;
			   sof = true;
		   } else

			   if(sof && !len && index == IX_LEN)
			   {
				   buffer[index++] = data;
				   len = true;
			   } else
				   if(len && index < buffer[IX_LEN])
			   {
				   buffer[index++] = data;
			   } else
				   if(index == (buffer[IX_LEN] - 1) && sof && len)
				   {
					   frameCompleted = true;

					   EVENT(evtNewFrame, this, HWFrame::FromBuffer(buffer) );

				   } else
				   {
					   error = true;
				   }

	   } else
	   {
		   error = true;
	   }

	   return !error;
	}

	bool HasError()
	{
		return error;
	}

	bool IsFrameCompleted()
	{
		return frameCompleted;
	}

	void ResetPointer()
	{
		memset((void*)buffer,0,MAX_FRAME_SIZE);
		index = 0;
		sof = false;

		error = false;
		frameCompleted = false;
		len = false;
	}

	void SetNewFrameCallback(IEvent<HWFrame> *ifr)
	{
		this->evtNewFrame = ifr;
	}

	IEvent<HWFrame> *GetNewFrameCallback()
	{
		return this->evtNewFrame;
	}

	HWFrame* GetHWFrame()
	{
		return HWFrame::FromBuffer(buffer);
	}

};



#endif /* INC_HWFRAMEPARSER_H_ */
