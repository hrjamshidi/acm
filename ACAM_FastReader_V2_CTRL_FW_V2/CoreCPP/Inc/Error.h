/*
 * Error.h
 *
 *  Created on: Jul 24, 2020
 *      Author: User
 */

#ifndef INC_ERROR_H_
#define INC_ERROR_H_

#include <stdint.h>
#include <stddef.h>
#include "Object.h"

#define EC_SOCKET_ERROR 0x0001
#define EC_DRIVER_ERROR 0x0002


enum ErrorSource
{
	ERR_SRC_0,
	ERR_SRC_1,
	ERR_SRC_2,
	ERR_SRC_3,
	ERR_SRC_4

};

class Error : Object
{

protected:

   uint32_t errorCode;
   ErrorSource errorSource;
   const char *errorMsg;

   Error(uint32_t ec, ErrorSource esrc, const char  *msg)
   {
       this->errorCode = ec;
       this->errorSource = esrc;
       this->errorMsg = msg;

   }

public:

   static Error* Build(uint32_t errorCode, ErrorSource src, const char *msg = NULL)
   {
	   return new Error(errorCode, src, msg);
   }


   uint32_t GetCode() { return this->errorCode; }
   ErrorSource GetSource() { return this->errorSource ; }
   const char *GetMessage() { return this->errorMsg; }

};


#endif /* INC_ERROR_H_ */
