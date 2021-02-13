/*
 * hwframe.h
 *
 *  Created on: Jul 17, 2020
 *      Author: User
 */

#ifndef INC_HWFRAME_H_
#define INC_HWFRAME_H_
#include <stdint.h>
#include <stddef.h>
#include "Object.h"

#define MAX_FRAME_SIZE		255
#define MIN_FRAME_SIZE 		4
#define MAX_ARG_SIZE 		(MAX_FRAME_SIZE-MIN_FRAME_SIZE)

#define IX_STX				0
#define IX_LEN				1
#define IX_CMD				2
#define IX_ARG				3
#define IX_LRC_NOARG		3

#define HWF_LEN(a) (a[IX_LEN])
#define HWF_

enum HWCommand
{
	HWCMD_Reset,
	HWCMD_Write,
	HWCMD_Read,
	HWCMD_Push,
	HWCMD_Pull
};

enum ControlCode
{
    CC_STX = 0x02,
	CC_EOT = 0x03
};


class HWFrame : public Object
{
public:
	HWFrame();
	HWFrame(const uint8_t*);
	HWFrame(const HWFrame&);
	HWFrame(HWCommand cmd, const uint8_t *args, uint8_t arglen);
	HWFrame(HWCommand cmd) : HWFrame(cmd,NULL,0 ) {  }
	virtual ~HWFrame()
	{
		if(frame != NULL)
		{
			delete frame;
			frame = NULL;
		}
	}

	uint16_t GetFrameLength()   const  { return frame[IX_LEN]; }
	uint16_t GetDataLength()    const  { return frame[IX_LEN] > MIN_FRAME_SIZE ? frame[IX_LEN] - MIN_FRAME_SIZE : 0 ; }

	const uint8_t *GetData()    const  { return (const uint8_t *)&frame[IX_ARG]; }
	HWCommand      GetCommand() const  { return (HWCommand)frame[IX_CMD];        }
	const uint8_t *GetFrame()   const  { return (const uint8_t *)frame;          }

	bool           HasLRCError() const { return HWFrame::LRC(frame, frame[IX_LEN]) != 0; }

	static uint8_t LRC(const uint8_t* data, uint16_t len=0)
	{
		uint8_t retV = 0;

		if(len == 0) len = data[IX_LEN];

		for(uint16_t i=0;i<len;i++)
		{
			if(i == 0 && data[i] == CC_STX) continue;

			retV ^= data[i];
		}

		return retV;
	}

	static HWFrame *FromBuffer(const uint8_t *data)
	{
		return new HWFrame(data);
	}



protected:
    uint8_t *frame;

};

#endif /* INC_HWFRAME_H_ */
