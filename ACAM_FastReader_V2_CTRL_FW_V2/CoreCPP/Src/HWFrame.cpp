/*
 * HWFrame.cpp
 *
 *  Created on: Jul 17, 2020
 *      Author: User
 */

#include "../Inc/HWFrame.h"
#include <cstring>


HWFrame::HWFrame()
{
  this->frame = NULL;
}


HWFrame::HWFrame(const HWFrame& hwf)
{
  this->frame = new uint8_t[hwf.GetFrameLength()];
  memcpy(this->frame, hwf.GetFrame(), hwf.GetFrameLength());

}


HWFrame::HWFrame(const uint8_t *buffer)
{
   this->frame = new uint8_t[buffer[IX_LEN]];
   memcpy(this->frame, buffer, buffer[IX_LEN]);
}


HWFrame::HWFrame(HWCommand cmd, const uint8_t *args, uint8_t arglen)
{
   this->frame = new uint8_t[MIN_FRAME_SIZE + arglen];
   this->frame[IX_STX] = CC_STX;
   this->frame[IX_LEN] = MIN_FRAME_SIZE + arglen;
   this->frame[IX_CMD] = (uint8_t)cmd;

   if(arglen > 0)
   {
	   memcpy(&(this->frame[IX_ARG]), args, arglen);
   }

   this->frame[MIN_FRAME_SIZE+arglen-1] = HWFrame::LRC((const uint8_t*)this->frame);
}
