#include "driver/tty.h"
#include <stddef.h>
#include "std/string.h"
#include "vkit/vkit.h"

window vkit_create_window(char *title, char x1, char x2, char y1, char y2)
{ 
	window win = { title, x1, x2, y1, y2 };
	if(y1 > y2)
		return vkit_create_window(title, x1, x2, y2, y1);
	else if(y1 == y2)
		return vkit_create_window(title, x1, x2, y1, y2 + 1);
	else if(x1 > x2)
		return vkit_create_window(title, x2, x1, y1, y2);
	else if(x1 == x2)
		return vkit_create_window(title, x1, x2 + 1, y1, y2);
	putchar_at(201, x1, y1);
	putchar_at(187, x2, y1);
	putchar_at(200, x1, y2);
	putchar_at(188, x2, y2);
	for(int y=y1+1;y<y2;y++) {
		putchar_at(186, x1, y);
		putchar_at(186, x2, y);
	}
	for(int x=x1+1;x<x2;x++) {
		putchar_at(205, x, y1);
		putchar_at(205, x, y2);
	}
	int idx = 0;
	putchar_at(' ', x1 + 2, y1);
	
	char *dtitle = truncate(title, (x2 - x1));
	int len = strlen(dtitle);
	for(int i=x1+3;i<x2-2;i++,idx++)
	{
		if(i >= (len + (x1 + 3)))
			continue;
		putchar_at(dtitle[idx], i, y1);
	}
	putchar_at(' ', (x1 + 3) + len, y1);
	return win;
}