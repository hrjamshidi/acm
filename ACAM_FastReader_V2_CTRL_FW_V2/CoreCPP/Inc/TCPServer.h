/*
 * TCPServer.h
 *
 *  Created on: Jul 24, 2020
 *      Author: User
 */

#ifndef INC_TCPSERVER_H_
#define INC_TCPSERVER_H_

#include <stdint.h>
#include <stddef.h>
#include "Error.h"
#include "Object.h"
#include <socket.h>
#include <string.h>

#include <lwip.h>

#include "IEvent.h"
#include "TCPClient.h"


#define DEFAULT_SERVER_PORT 2364

class TCPServer : public Object
{

protected:

	int16_t socketFd;
	DEFINE_EVENT(Error,Error)
	DEFINE_EVENT(TCPClient, NewClient)
	//IEvent<Error> *evtError;
	//IEvent<TCPClient> *evtNewClient;

	uint16_t port;
	bool     run;

public:

	TCPServer(uint16_t port = DEFAULT_SERVER_PORT)
	{
	   this->port = port;
	}

	void Startup();
	void Shutdown();

	bool IsRun() { return this->run; }

	IMPLEMENT_EVENT(Error,Error)
	IMPLEMENT_EVENT(TCPClient, NewClient)
};


#endif /* INC_TCPSERVER_H_ */
