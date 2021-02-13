/*
 * ILogger.h
 *
 *  Created on: Aug 13, 2020
 *      Author: User
 */

#ifndef INC_ILOGGER_H_
#define INC_ILOGGER_H_

#include "Object.h"

#define DEFINE_LOGGER 		ILogger *logger;
#define ASSIGN_LOGGER(log)  this->logger = log;
#define LOG(t,msg)			{ if(this->logger) logger->Log(t,msg); }

enum LogType
{
	LOG_INFO,
	LOG_DEBUG,
	LOG_ERROR,
	LOG_VERBOSE
};

class ILogger : public Object
{
public:
	virtual void Log(LogType lt, const char *message ) = 0;
};



#endif /* INC_ILOGGER_H_ */
