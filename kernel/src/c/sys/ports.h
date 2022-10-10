#ifndef SYS_PORTS_H
#define SYS_PORTS_H

#include <stdint.h>

/**
 *
 * Читает из порта, и возвращает 8-битный результат.
 *
 * @param порт
 *
 */
uint8_t inb(uint16_t);

/**
 *
 * Читает из порта, и возвращает 16-битный результат.
 *
 * @param порт
 *
 */
uint16_t inw(uint16_t);

/**
 *
 * Читает из порта, и возвращает 32-битный результат.
 *
 * @param порт
 *
 */
uint32_t inl(uint16_t);

/**
 *
 * Отправляет 8-битные данные пакета в порт.
 *
 * @param порт
 * @param данные
 *
 */
void outb(uint16_t, uint8_t);

/**
 *
 * Отправляет 16-битные данные пакета в порт.
 *
 * @param порт
 * @param данные
 *
 */
void outw(uint16_t, uint16_t);

/**
 *
 * Отправляет 32-битные данные пакета в порт.
 *
 * @param порт
 * @param данные
 *
 */
void outl(uint16_t, uint32_t);

#endif /* SYS_PORTS_H */