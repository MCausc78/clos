#include "std/bool.h"

bool bool_and(bool a, bool b) {
	return (a ? (b ? true : false) : false);
}

bool bool_or(bool a, bool b) {
	return (a ? true : (b ? true : false));
}

bool bool_negate(bool a) {
	return a ? false : true;
}

char *bool_to_string(bool a) {
	return a ? "true" : "false";
}

bool bool_xor(bool a, bool b) {
	return (a ? !b : b);
}