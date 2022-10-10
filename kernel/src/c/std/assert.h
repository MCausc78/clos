#ifndef _STD_ASSERT_H
#define _STD_ASSERT_H

#ifdef NDEBUG
#define assert(expr)
#else
#define assert(expr) (void)((expr) || (__assert(#expr, __FILE__, __LINE__), 0));
#endif /* NDEBUG */

extern void __assert(const char *, const char *, int);

// Assertion failed: 2 == 4 && "?", file assert.c, line 6

#endif /* _STD_ASSERT_H */