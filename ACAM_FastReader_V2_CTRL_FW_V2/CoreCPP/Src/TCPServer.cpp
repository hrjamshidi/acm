/*
 * TCPServer.cpp
 *
 *  Created on: Jul 24, 2020
 *      Author: User
 */


#include "../Inc/TCPServer.h"


void TCPServer::Startup()
{
   struct sockaddr_in localAddress;

   this->socketFd = socket(PF_INET,SOCK_STREAM,0);

   if(this->socketFd < 0)
   {
	   EVENT(evtError, this, Error::Build(EC_SOCKET_ERROR, ERR_SRC_0, "socket error !"));

	   return;
   }

   memset(&localAddress,0,sizeof(localAddress));

   localAddress.sin_port = htons(this->port);
   localAddress.sin_family = AF_INET;
   localAddress.sin_len = sizeof(localAddress);
   localAddress.sin_addr.s_addr = htonl(INADDR_ANY);

   if(bind(socketFd, (struct sockaddr *) &localAddress, sizeof(localAddress)) < 0)
   {
	   closesocket(socketFd);

	   EVENT(evtError, this, Error::Build(EC_SOCKET_ERROR, ERR_SRC_1, "Bind error !"));


	   return;
   }


   if(listen(socketFd,20) != 0)
   {
	   EVENT(evtError, this, Error::Build(EC_SOCKET_ERROR, ERR_SRC_2, "Listen error !"));

	   closesocket(socketFd);
	   return;
   }


   this->run = true;

   while(this->run)
   {
	   struct sockaddr_in  clientAddr;
	   int16_t addrLen = 0;

       int16_t clientSocketFd = accept(socketFd,  (struct sockaddr *)&clientAddr, (socklen_t*)&addrLen);

       if(clientSocketFd > 0)
       {
    	   EVENT(evtNewClient, this, new TCPClient(clientSocketFd, &clientAddr));
    	  // else
    		//   closesocket(clientSocketFd);
       } else
       {
    	   EVENT(evtError, this, Error::Build(EC_SOCKET_ERROR, ERR_SRC_3, "Client socket error !"));
       }
   }

   closesocket(socketFd);

   this->run = true;

}



void TCPServer::Shutdown()
{
   this->run = false;

   while(!this->run);

   this->run = false;
}

