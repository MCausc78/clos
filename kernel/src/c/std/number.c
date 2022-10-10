#include "std/number.h"

int intlen(int num)
{
	int len = 0;
	int n = num + 0;
	while(n != 0) {
		len++;
		n /= 10;
	}
	return len;
}

unsigned char digit_to_hex(int digit) {
	return (digit >= 0 && digit <= 15) ? "0123456789abcdef"[digit] : '?';
}
