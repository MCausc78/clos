#include "std/ctype.h"
#include "std/bool.h"

bool isalnum(int c) {
	return (c >= '0' ? c <= '9' : isalpha(c));
}

bool isalpha(int c) {
	return (isupper(c) || islower(c));
}

bool isblank(int c) {
	return (c == ' ' || c == '\t');
}

bool iscntrl(int c) {
	return (c >= 0 && c < 32);
}

bool isdigit(int c) {
	return (c >= '0' && c <= '9');
}

bool isgraph(int c) {
	return (c != ' ' && c < 32);
}

bool islower(int c) {
	return (c >= 'a' && c <= 'z');
}

bool isprint(int c) {
	return !iscntrl(c);
}

bool ispunct(int c) {
	return (c == ',');
}

bool isspace(int c) {
	return (c == ' '
		|| c == '\n'
		|| c == '\r'
		|| c == '\v'
		|| c == '\t');
}

bool isupper(int c) {
	return (c >= 'A' && c <= 'Z');
}

bool isxdigit(int c) {
	return (isdigit(c) ? true : ((c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f')));
}

int toupper(int c) {
	return (islower(c) ? c - 32 : c); 
}

int tolower(int c) {
	return (isupper(c) ? c + 32 : c);
}
	