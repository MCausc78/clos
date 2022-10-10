#include "std/assert.h"
#include "std/io.h"

void __assert(const char *expr, const char *file, int line) {
	printf("Asserton failed: %s, file %s, line %i", expr, file, line);
}

// Assertion failed: 2 == 4 && "?", file assert.c, line 6
