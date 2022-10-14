#include "std/stdio.h"
#include <stdarg.h>
#include <stdint.h>
#include "std/stdbool.h"
#include "std/string.h"
#include "std/number.h"
#include "driver/tty.h"

const int EOF = -1;

int print_data(const char *data, size_t size) 
{
	int total = 0;
	for (size_t i = 0; i < size; i++, total++)
		putchar(data[i]);
	return total;
}

int print(const char *str)
{
	return print_data(str, strlen(str));
}

int print_i(int num) {
	char str[intlen(num)];
	return print(itoa(str, num, 10));
}

int printf(const char *format, ...) {
	va_list val;
	va_start(val, format);
	int total = vprintf(format, val);
	va_end(val);
	return total;
}

int vprintf(const char *format, va_list val) {
	int total = 0;
	int ch;
	for(int i=0;(ch = format[i]);i++, total++) {
		if(ch == '%') {
			int ch2 = format[++i];
			if(ch2 == 'B') {
				bool bl = (bool)(va_arg(val, bool));
				print(bool_to_string(bl));
				total += (bl ? 5 : 4);
			} else if (ch2 == 'c') {
				int cl = va_arg(val, int);
				putchar(cl);
				total++;
			} else if (ch2 == 'i') {
				int il = (int)(va_arg(val, int));
				total += print_i(il);
			} else if(ch2 == 's') {
				char *s = va_arg(val, char*);
				total += print(s);
			} else if(ch2 == 'x') {
				int il = (int)(va_arg(val, int));
				char str[intlen(il)];
				total += print(string_tolower(itoa(str, il, 16)));
			} else if(ch2 == 'X') {
				int il = (int)(va_arg(val, int));
				char str[intlen(il)];
				total += print(string_toupper(itoa(str, il, 16)));
			} else if(ch2 == '%') {
				putchar('%');
			} else {
				putchar('%');
				putchar(ch2);
				total++;
			}
			continue;
		}
		putchar(ch);
	}
	return total;
}

int printc(const char *str, uint8_t color) {
	uint8_t dc = term_color + 0;
	tty_setcolor(color);
	int rs = print(str);
	tty_setcolor(dc);
	return rs;
}

int println(const char *str)
{
	int rs = print(str);
	putchar(0x0A);
	return rs;
}

int printlnc(const char *str, uint8_t color) {
	uint8_t dc = term_color + 0;
	tty_setcolor(color);
	int rs = println(str);
	tty_setcolor(dc);
	return rs;
}