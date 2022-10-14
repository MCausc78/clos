#include "std/assert.h"
#include "std/stdbool.h"
#include "std/ctype.h"
#include "std/number.h"
#include "std/string.h"

#include <stdint.h>
#include <stddef.h>

void *memcpy(void *dest, const void *src, size_t n) {
	unsigned char* destv = (unsigned char*) dest;
	const unsigned char* srcv = (const unsigned char*) src;

	for(size_t i = 0; i < n; i++)
		destv[i] = srcv[i];

	return dest;
}

void *memmove(void *dest, const void *src, size_t n) {
	unsigned char *destv = (unsigned char*) dest;
	const unsigned char* srcv = (const unsigned char*) src;
	
	if(destv < srcv) {
		for(size_t i = 0; i < n; i++)
			destv[i] = srcv[i];
	} else {
		for(size_t i = n; i != 0; i--)
			destv[i - 1] = srcv[i - 1];
	}
	
	return dest;
}

// void *memchr(const char *s, char c, size_t n);

char memcmp(const void *a, const void *b, size_t n) {
	const unsigned char* av = (const unsigned char*)a;
	const unsigned char* bv = (const unsigned char*)b;
	for (size_t i = 0; i < n; i++) {
		if (av[i] < bv[i])
			return -1;
		else if (bv[i] < av[i])
			return 1;
	}
	return 0;
}

void *memset(void *buf, int z, size_t n) {
	unsigned char* bufv = (unsigned char*) buf;
	for(size_t i = 0; i < n; i++)
		bufv[i] = (unsigned char) z;
	return buf;
}

size_t strlen(const char *s)
{
	size_t l = 0; while(s[l]!=0)++l;
	return l;
}

char *strrev(char *buf, const char *s) {
	// получаем длину строки
	/*int len = strlen(s);
	int idx = 0;
	// копируем контент
	for(int i=len - 1; i>=0; i--) {
		buf[idx++] = s[i];
	}
	return buf;*/
	for(int c, i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		buf[i] = s[j];
		buf[j] = c;
	}
	return buf;
}

bool strcmp(const char *s1, const char *s2) {
	if(strlen(s1) == strlen(s2)) {
		int len = strlen(s1);
		for(int i=0; i < len; i++) {
			if(s1[i] != s2[i])
				return false;
		}
		return true;
	} else return false;
}

char *strcat(char *s1, const char *s2) {
	//for(int i=strlen(s1)-1; s2[i] != 0; i++) s1[i] = s2[i];
	//s1[((strlen(s1)-1) + (strlen(s2)-1))] = 0;
	//return s1;
	size_t i, j;
	for(i = 0; s1[i] != '\0'; i++);
	for(j = 0; s2[j] != '\0'; j++)
		s1[i + j] = s2[j];
	s1[i + j] = 0;
	i = 0;
	j = 0;
	return s1;
}

char *strcpys(int start, char *s1, const char *s2) {
	for(int i=start;s2[i-start];i++) {
		s1[i] = s2[i-start];
	}
	return s1;
}

char *strcpy(char *s1, const char *s2) {
	return strcpys(0, s1, s2);
}

char *truncate(char *str, int mlen)
{
	int len = strlen(str);
	if(len > mlen)
	{
		str[mlen] = '.';
		str[mlen + 1] = '.';
		str[mlen + 2] = '.';
		str[mlen + 3] = 0x00;
		return str;
	}
	return str;
}


//size_t strspn (const char *str1, const char *str2) {
//	
//}


char *itoa(char *buf, int n, unsigned base) {
	assert((base > 1 && base <= 36) && "unknown base");
	char syms[] = "0123456789abcdef";
	if(n < 0) {
//		n *= -1;
		asm("negl %0" : "=r"(n));
		char b[intlen(n) + 2];
		itoa(b, n, base);
		buf[0] = '-';
		return strcpys(1, buf, b);
	} else if(n >= 0 && n <= 9) {
		buf[0] = n + '0';
		buf[1] = 0;
		return buf;
	}
	int l = intlen(n);
	int idx = l - 1;
	do {
		buf[idx--] = syms[n % base];
	} while(n /= base);
	
	buf[l] = 0;
	// переверни строку!
	char rstr[++l];
	strrev(rstr, buf);
	// готово
	strcpy(buf, rstr);
	buf[strlen(buf)] = 0;
	return buf;
}

char *ubyte_tobinary(char *buf, unsigned char num) {
	unsigned char n = num + 0;
	//char buf[8];
	buf[8] = 0;
	for(int i=0; i<8; i++)
		buf[i] = '0';
	
	for(int idx = 7; idx >= 0; n>>=1) {
		buf[idx--] = (n & 1) + '0';
	}
	return buf;
}

char *ushort_tobinary(char *buf, unsigned short num) {
	unsigned short n = num + 0;
	//char buf[16];
	buf[16] = 0;
	for(int i=0; i<16; i++)
		buf[i] = '0';
	
	for(int idx = 15; idx >= 0; n>>=1) {
		buf[idx--] = (n & 1) + '0';
	}
	return buf;
}

char *uint_tobinary(char *buf, unsigned int num) {
	unsigned int n = num + 0;
	//char buf[32];
	buf[32] = 0;
	for(int i=0; i<32; i++)
		buf[i] = '0';
	
	for(int idx = 31; idx >= 0; n>>=1) {
		buf[idx--] = (n & 1) + '0';
	}
	return buf;
}
char *ulong_tobinary(char *buf, unsigned long num) {
	unsigned long n = num + 0;
	//char buf[32];
	buf[64] = 0;
	for(int i=0; i<64; i++)
		buf[i] = '0';
	
	for(int idx = 63; idx >= 0; n>>=1) {
		buf[idx--] = (n & 1) + '0';
	}
	return buf;
}


char *byte_tobinary(char *buf, char num) {
	char n = num + 0;
	//char buf[8];
	buf[8] = 0;
	for(int i=0; i<8; i++)
		buf[i] = '0';
	
	for(int idx = 7; idx > 0; n>>=1) {
		buf[idx--] = (n & 1) + '0';
	}
	return buf;
}

char *short_tobinary(char *buf, short num) {
	short n = num + 0;
	//char buf[16];
	buf[16] = 0;
	for(int i=0; i<16; i++)
		buf[i] = '0';
	
	for(int idx = 15; idx > 0; n>>=1) {
		buf[idx--] = (n & 1) + '0';
	}
	return buf;
}

char *int_tobinary(char *buf, int num) {
	int n = num + 0;
	//char buf[32];
	buf[32] = 0;
	for(int i=0; i<32; i++)
		buf[i] = '0';
	
	for(int idx = 31; idx > 0; n>>=1) {
		buf[idx--] = (n & 1) + '0';
	}
	return buf;
}

char *long_tobinary(char *buf, long num) {
	long n = num + 0;
	//char buf[32];
	buf[64] = 0;
	for(int i=0; i<64; i++)
		buf[i] = '0';
	for(int idx = 63; idx > 0; n>>=1) {
		buf[idx--] = (n & 1) + '0';
	}
	return buf;
}

unsigned char binary_toubyte(char *bin) {
	unsigned char uc = 0;
	for(int i = (strlen(bin) - 1), j = 0; i >= 0; i--, j++) uc += (bin[i] - '0')<<j;
	return uc;
}
unsigned short binary_toushort(char *bin) {
	unsigned short us = 0;
	for(int i = (strlen(bin) - 1), j = 0; i >= 0; i--, j++) us += (bin[i] - '0')<<j;
	return us;
}
unsigned int binary_touint(char *bin) {
	unsigned short ui = 0;
	for(int i = (strlen(bin) - 1), j = 0; i >= 0; i--, j++) ui += (bin[i] - '0')<<j;
	return ui;
}

unsigned long binary_toulong(char *bin) {
	unsigned long ul = 0;
	for(int i = (strlen(bin) - 1), j = 0; i >= 0; i--, j++) ul += (bin[i] - '0')<<j;
	return ul;
}

char binary_tobyte(char *bin) {
	char b = 0;
	for(int i = (strlen(bin) - 1), j = 0; i >= 0; i--, j++) b += (bin[i] - '0')<<j;
	return b;
}

short binary_toshort(char *bin) {
	short s = 0;
	for(int i = (strlen(bin) - 1), j = 0; i >= 0; i--, j++) s += (bin[i] - '0')<<j;
	return s;
}

int binary_toint(char *bin) {
	long r = 0;
	for(int i = (strlen(bin) - 1), j = 0; i >= 0; i--, j++) r += (bin[i] - '0')<<j;
	return r;
}
long binary_tolong(char *bin) {
	long l = 0;
	for(int i = (strlen(bin) - 1), j = 0; i >= 0; i--, j++) l += (bin[i] - '0')<<j;
	return l;
}

char *string_toupper(char *str) {
	for(int i=0, len=strlen(str); i<len; i++) str[i] = toupper(str[i]);
	return str;
}

char *string_tolower(char *str) {
	for(int i=0, len=strlen(str); i<len; i++) str[i] = tolower(str[i]);
	return str;
}

char *string_append(char *str, char ch) {
	int len = strlen(str);
	str[len] = ch;
	str[++len] = 0;
	return str;
}
char *string_delete_last(char *str) {
	int len = strlen(str);
	if(len > 0)
		str[--len] = 0;
	return str;
}