/*
 * CommandParser.h
 *
 *  Created on: Jan 7, 2021
 *      Author: User
 */

#ifndef INC_COMMANDPARSER_H_
#define INC_COMMANDPARSER_H_

#include "Object.h"
#include "IEvent.h"
#include <cstring>

#define MAX_CMD_LEN 128

#define CMD_END     0x0A

typedef char* pCMD;

class CommandParser: public Object
{
protected:
	char  buffer[MAX_CMD_LEN];
	uint16_t index;
    bool     cmdCompleted;
    bool     error;
    DEFINE_EVENT(char,NewCommand)

public:

    CommandParser()
	{
		this->evtNewCommand = NULL;
		ResetPointer();
	}

	virtual ~CommandParser()
	{

	}

	bool Push(char data)
	{
	   if(index < (MAX_CMD_LEN-1) && !cmdCompleted)
	   {
	     if(data != CMD_END)
	     {
            buffer[index++] = data;
	     } else
	     {
	    	 cmdCompleted = true;

	    	 char* cmd = new char[index];
	    	 memcpy(cmd, this->buffer, index);

	    	 EVENT(evtNewCommand,this, cmd);
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

	bool IsCmdCompleted()
	{
		return cmdCompleted;
	}

	void ResetPointer()
	{
		memset((void*)buffer,0,MAX_CMD_LEN);
		index = 0;
		error = false;
		cmdCompleted = false;
	}

    IMPLEMENT_EVENT(char,NewCommand)

};

#endif /* INC_COMMANDPARSER_H_ */
