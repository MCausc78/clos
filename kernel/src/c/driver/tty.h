#ifndef _TERMINAL_DRIVER_H
#define _TERMINAL_DRIVER_H

#include<stddef.h>
#include<stdint.h>

extern size_t row;
extern size_t col;
extern uint8_t term_color;
extern uint16_t* term_buf;

/**
 *
 * Возвращает цвет по умолчанию.
 *
 */
void set_default_color(void);

void set_row(size_t);

void set_col(size_t);

/**
 *
 * Чистит экран.
 *
 */
void clear(void);

/**
 *
 * Скроллит терминал.
 *
 */
void tty_scroll(void);

/**
 *
 * Установить цвет.
 *
 * @param цвет
 *
 */
void tty_setcolor(uint8_t);

/**
 *
 * Нарисовать цветный символ на `x` и `y`.
 *
 * @param символ
 * @param цвет
 * @param позиция x
 * @param позиция y
 *
 */
void putcchar_at(char, uint8_t, size_t, size_t);

/**
 *
 * Нарисовать символ на `x` и `y`.
 *
 * @param символ
 * @param позиция x
 * @param позиция y
 *
 */
void putchar_at(char, size_t, size_t);


/**
 *
 * Вывести символ.
 *
 * @param символ
 *
 */
void putchar(char);

/**
 *
 * Вывести цветной символ.
 *
 * @param символ
 *
 */
void putcchar(char, uint8_t);

#endif /* _TERMINAL_DRIVER_H */