#ifndef _STRING_H
#define _STRING_H

#include "std/bool.h"
#include <stddef.h>
#include <stdint.h>

void *memcpy(void *, const void *, size_t);

void *memmove(void *, const void *, size_t);

void *memchr(const void *, void *, size_t);

char memcmp(const void *, const void *, size_t);

void *memset(void *, int, size_t);

/**
 *
 * Возвращает длину строки.
 *
 * @param строка
 *
 */
size_t strlen(const char *);

/**
 *
 * Записывает в буфер перевернутую строку
 *
 * @param буфер
 * @param строка, которую нужно перевернуть
 *
 */
char *strrev(char *, const char *);

/**
 *
 * Сравнивает две строки, и возвращает результат.
 *
 * @param строка 1
 * @param строка 2
 *
 */
bool strcmp(const char *, const char *);

char *strcat(char *, const char *);

/**
 *
 * Копирует строку в другую строку начиная с начала.
 *
 * @param начало
 * @param строка 1
 * @param строка 2
 *
 */

char *strcpys(int, char *, const char *);

/**
 *
 * Копирует строку в другую строку.
 *
 * @param строка 1
 * @param строка 2
 *
 */
char *strcpy(char *, const char *);

char *truncate(char *, int);

/**
 *
 * Превращает цифру в строку.
 *
 * @param буфер
 * @param цифра
 *
 */
char *itoa(char *, int, unsigned);

char *ubyte_tobinary(char *, unsigned char);
char *ushort_tobinary(char *, unsigned short);
char *uint_tobinary(char *, unsigned int);
char *ulong_tobinary(char *, unsigned long);

char *byte_tobinary(char *, char);
char *short_tobinary(char *, short);
char *int_tobinary(char *, int);
char *long_tobinary(char *, long);

unsigned char binary_toubyte(char *);
unsigned short binary_toushort(char *);
unsigned int binary_touint(char *);
unsigned long binary_toulong(char *);

char binary_tobyte(char *);
short binary_toshort(char *);
int binary_toint(char *);
long binary_tolong(char *);

char *string_toupper(char *);
char *string_tolower(char *);

char *string_append(char *, char);
char *string_delete_last(char *);

#endif /* _STRING_H */