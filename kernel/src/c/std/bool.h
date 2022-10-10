#ifndef _STDBOOL_H
#define _STDBOOL_H

typedef enum { false = 0, true = 1, } bool;

bool bool_and(bool, bool);

bool bool_or(bool, bool);

bool bool_negate(bool);

char *bool_to_string(bool a);

bool bool_xor(bool, bool);

#endif /* _STDBOOL_H */