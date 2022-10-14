#ifndef _STD_TIME_H
#define _STD_TIME_H

#include "std/stdbool.h"

struct tm
{
	int tm_sec;
	int tm_min;
	int tm_hour;
	int tm_mday;
	int tm_mon;
	int tm_year;
	bool tm_isdst;
};

typedef unsigned long time_t;

time_t time(time_t *);

#endif /* _STD_TIME_H */

// time_t utm = years *