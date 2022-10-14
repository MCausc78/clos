#ifndef _STD_ASSERT_H
#define _STD_ASSERT_H

#ifdef NDEBUG
#define assert(expr)
#else
#define assert(expr) (void)((expr) || (__assert(#expr, __FILE__, __LINE__), 0));
#endif /* NDEBUG */

extern void __assert(const char *, const char *, int);

#endif /* _STD_ASSERT_H */