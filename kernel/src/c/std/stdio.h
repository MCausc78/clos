#ifndef _STDIO_H
#define _STDIO_H

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

extern const int EOF;

/**
 *
 * Печатает данные.
 *
 * @param данные
 * @param количество данных
 *
 */
int print_data(const char *, size_t);

/**
 *
 * Печатает строку.
 *
 * @param строка
 *
 */
int print(const char *);

/**
 *
 * Печатает цифру.
 *
 * @param цифра
 *
 */
int print_i(int);

/**
 *
 * Печатает форматированную строку.
 *
 * @param формат
 * @param ...
 *
 */
int printf(const char *, ...);

/**
 *
 * Печатает форматированную строку.
 *
 * @param формат
 * @param список
 *
 */
int vprintf(const char *, va_list);

/**
 *
 * То же самое что и print, только с аргументом цвета.
 *
 * @param строка
 *
 */
int printc(const char *, uint8_t);

/**
 *
 * То же самое что и print, только печатает в добавок символ новой строки.
 *
 * @param строка
 *
 */
int println(const char *);

/**
 *
 * То же самое что и printc, только печатает в добавок символ новой строки.
 *
 * @param строка
 *
 */

int printlnc(const char *, uint8_t);

#endif /* _STDIO_H */