#ifndef _SYS_BITSET_H
#define _SYS_BITSET_H

#include "std/stdbool.h"

typedef struct {
	unsigned short part1;
	unsigned short part2;
} bitset;

/**
 *
 * Создает новый объект bitset.
 *
 */
bitset bitset_create();

/**
 *
 * Получить значение флага.
 *
 * @param объект
 * @param ключ
 *
 */
bool bitset_is_bit_enabled(bitset *, unsigned char);

/* 
 *
 * Установить значение бита у объекта в bool.
 *
 * @param объект
 * @param ключ
 * @param значение
 *
 */
void bitset_set_bit(bitset *, unsigned char, bool);

/* 
 *
 * Конвертирование объекта bitset в строку.
 *
 * @param объект
 * @param буфер
 *
 */
char *bitset_tostring(bitset *, char *);

unsigned int bitset_pack(bitset *);

bitset bitset_unpack(unsigned int);

unsigned char bitset_length(bitset *);

#endif /* _SYS_BITSET_H */