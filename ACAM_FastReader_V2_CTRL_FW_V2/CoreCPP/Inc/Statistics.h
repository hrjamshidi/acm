/*
 * Statistics.h
 *
 *  Created on: Jan 7, 2021
 *      Author: User
 */

#ifndef INC_STATISTICS_H_
#define INC_STATISTICS_H_

typedef struct
{
	int   Stat1;
	int   Stat2;
	int   Stat3;
	int   Stat4;
} SysStat;

extern "C" SysStat SystemStatistics;

#endif /* INC_STATISTICS_H_ */
