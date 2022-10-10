#ifndef _STD_LIB_H
#define _STD_LIB_H

#include "std/bool.h"
#include <stddef.h>
#include <stdint.h>

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0
#undef NULL
#define NULL ((void*)0)
#define RAND_MAX 32768

// https://stackoverflow.com/questions/142508/how-do-i-check-os-with-a-preprocessor-directive
#if defined(__ANDROID__)
#define PLATFORM "Linux/Android"
#elif defined(__CYGWIN__)
#define PLATFORM "Windows/Cygwin"
#elif defined(__MINGW64__)
#define PLATFORM "Windows/MinGW-w64"
#elif defined(WINNT)
#define PLATFORM "Windows/NT"
#elif defined(_WIN64) || defined(WIN64)
#define PLATFORM "Windows/64"
#elif defined(_WIN32) || defined(WIN32)
#define PLATFORM "Windows/32"
#elif defined(__linux__)
#define PLATFORM "GNU/Linux"
#elif defined(__unix__) || !defined(__APPLE__) && defined(__MACH__)
#include<sys/param.h>
#if defined(BSD)
#if defined(__FreeBSD__)
#define PLATFORM "Unix/FreeBSD"
#elif defined(__NetBSD__)
#define PLATFORM "Unix/NetBSD"
#elif defined(__OpenBSD__)
#define PLATFORM "Unix/OpenBSD"
#elif defined(__DragonFly__)
#define PLATFORM "FreeBSD/DragonFly"
#else
#define PLATFORM "Unix/BSD"
#endif /* BSD */
#else
#define PLATFORM "Unix"
#endif
#elif defined(__hpux)
#define PLATFORM "Unix/HP-UX"
#elif defined(_AIX)
#define PLATFORM "Unix/AIX"
#elif defined(__APPLE__) && defined(__MACH__)
#include <TargetConditionals.h>
#if TARGET_IPHONE_SIMULATOR == 1 || TARGET_OS_IPHONE == 1
#define PLATFORM "Apple/iOS"
#elif TARGET_OS_MAC == 1
#define PLATFORM "Apple/OSX"
#else
#define PLATFORM "Apple/Unknown"
#endif
#if defined(sun) || defined(__sun)
#if defined(__SVR4) || defined(__svr4__)
#define PLATFORM "Unix/Solaris"
#else
#define PLATFORM "Unix/SunOS"
#endif /* SOLARIS_OR_SUNOS */
#endif /* SUN */
#else
#define PLATFORM "Unknown"
#endif /* PLATFORM */

// https://stackoverflow.com/questions/152016/detecting-cpu-architecture-compile-time
#if defined(__amd64__) || defined(__amd64) || defined(__x86_64__) || defined(__x86_64) || defined(_M_X64) || defined(_M_AMD64)
#define ARCH "x86-64"
#elif defined(__aarch64__)
#define ARCH "AArch64"
#elif defined(__arm__) || defined(_ARM) || defined(_M_ARM) || defined(_M_ARMT) || defined(__arm)
#define ARCH "ARM"
#elif defined(i386) || defined(__i386) || defined(__i386__) || defined(__i486__) || defined(__i586__) || defined(__i686__) || defined(__IA32__) || defined(_M_I86) || defined(_M_IX86) || defined(__X86__) || defined(_X86_) || defined(__386)
#define ARCH "x86"
#elif defined(__m68k__)
#define ARCH "m68k"
#elif defined(__mips__) || defined(mips) || defined(__mips) || defined(__MIPS__)
#define ARCH "MIPS"
#elif defined(__powerpc) || defined(__powerpc__) || defined(__powerpc64__) || defined(__POWERPC__) || defined(__ppc__) || defined(__ppc64__) || defined(__PPC__) || defined(__PPC64__) || defined(_M_PPC)
#define ARCH "PowerPC"
#elif defined(__sparc__) || defined(__sparc)
#define ARCH "SPARC"
#elif defined(__s390__) || defined(__s390x__) || defined(__zarch__)
#define ARCH "s390x"
#else
#define ARCH "Unknown"
#endif

typedef struct {
	bool status;
	uint32_t size;
} alloc_t;
	

extern unsigned long int next;

/**
 *
 * Превращает строку в int.
 *
 * @param строка
 *
 */
int atoi(const char *);

/**
 *
 * Превращает строку в long int.
 *
 * @param строка
 *
 */
long int atol(const char *);

/**
 *
 * Превращает строку в long long int.
 *
 * @param строка
 *
 */
long long int atoll(const char *);

int rand(void);

void srand(unsigned int);

void *malloc(size_t);

void *calloc(size_t, size_t);

void realloc(void *, size_t);

void free(void *);

#endif /* _STD_LIB_H */