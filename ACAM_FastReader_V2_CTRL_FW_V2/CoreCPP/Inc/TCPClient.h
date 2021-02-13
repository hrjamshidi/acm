/*
 * TCPClient.h
 *
 *  Created on: Jul 30, 2020
 *      Author: User
 */

#ifndef INC_TCPCLIENT_H_
#define INC_TCPCLIENT_H_


#include <stdint.h>
#include <stddef.h>
#include "Error.h"
#include "Object.h"
#include <socket.h>
#include <string.h>
#include "IDevice.h"
#include <lwip.h>
#include "HWFrame.h"
#include "HWFrameParser.h"

#include "IEvent.h"

class TCPClient : public IDevice
{
protected:

	int16_t socketFd;
	struct sockaddr_in *clientAddress;

	DEFINE_EVENT(Error,Error)

public:

	TCPClient(int16_t socket_fd, struct sockaddr_in *addr)
	{
		this->socketFd = socket_fd;
		this->clientAddress = (struct sockaddr_in*)(new sockaddr);

		memcpy(this->clientAddress, addr, sizeof(sockaddr_in));

	}


	virtual ~TCPClient()
	{
		closesocket(this->socketFd);
		if(this->clientAddress)
		{
			delete this->clientAddress;
			this->clientAddress = NULL;
		}
	}



	virtual bool SendFrame(const HWFrame* frame) override
	{
		uint8_t *data = (uint8_t*)frame->GetFrame();
		uint16_t len = frame->GetFrameLength();


		send(this->socketFd, data, len, 0);

		return true;

	}



	virtual HWFrame* RecieveFrame() override
	{
		uint16_t len = 0;
		uint8_t  buffer[MAX_FRAME_SIZE];

		HWFrameParser *parser = new HWFrameParser();

		do
		{
			len = recv(this->socketFd,(void*) buffer, (size_t)sizeof(buffer),0);

			for(;len>=0;len--)
			{
				parser->Push(buffer[len]);

				if(parser->IsFrameCompleted()) break;
			}

		}while(!parser->IsFrameCompleted());


        HWFrame *rv = parser->GetHWFrame();

        delete parser;
        //parser = NULL;

        return rv;
	}


	IMPLEMENT_EVENT(Error,Error)



};



#endif /* INC_TCPCLIENT_H_ */
