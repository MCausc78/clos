#include "std/stdlib.h"
#include "std/bool.h"

unsigned long int next = 1;

int atoi(const char *s)
{
	int n = 0;
	for(int i=0;s[i];i++)
	{
		n *= 10;
		n += s[i] - 48;
	}
	return n;
}

long int atol(const char *s) {
	long int n = 0;
	for(int i=0;s[i];i++)
	{
		n *= 10;
		n += s[i] - 48;
	}
	return n;
}

long long int atoll(const char *s) {
	long long int n = 0;
	for(int i=0;s[i];i++)
	{
		n *= 10;
		n += s[i] - 48;
	}
	return n;
}

int rand(void)
{
	next = next * 1103515245 + 12345;
	return (unsigned int) (next / 65536) % RAND_MAX;
}

void srand(unsigned int seed)
{
	next = seed;
}

/*char* malloc(size_t size) {
	char m[size];
	return m;
}

void *calloc(size_t nmemb, size_t size) {}

void realloc(void *ptr, size_t size) {}

void free(void *ptr) {}*/

