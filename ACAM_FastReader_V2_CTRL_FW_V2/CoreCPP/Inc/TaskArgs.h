/*
 * TaskArgs.h
 *
 *  Created on: Jan 7, 2021
 *      Author: User
 */

#ifndef INC_TASKARGS_H_
#define INC_TASKARGS_H_

#include "DriverRegistery.h"

typedef struct
{
	DriverRegistery  *driver;
	bool              run;

} TaskArgs, *pTaskArgs;


#endif /* INC_TASKARGS_H_ */
