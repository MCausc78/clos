#include "std/assert.h"
#include "std/stdio.h"

void __assert(const char *expr, const char *file, int line) {
	printf("Assertion failed: %s, file %s, line %i", expr, file, line);
}