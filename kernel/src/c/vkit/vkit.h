#ifndef _VKIT_H
#define _VKIT_H

#include "std/stdbool.h"

typedef struct
{
	char *title;
	int x1;
	int x2;
	int y1;
	int y2;
} window;

extern window vkit_create_window(char *, char, char, char, char);

#endif /* _VKIT_H */