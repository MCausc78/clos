#include "sys/ports.h"

#include <stdint.h>

uint8_t inb(uint16_t port)
{
	uint8_t r;
	asm volatile("inb %1, %0" : "=a"(r) : "d"(port));
	return r;
}
uint16_t inw(uint16_t port)
{
	uint16_t r;
	asm volatile("inw %1, %0" : "=a"(r) : "d"(port));
	return r;
}
uint32_t inl(uint16_t port) {
	uint32_t r;
	asm volatile("inl %1, %0" : "=a"(r) : "d"(port));
	return r;
}

void outb(uint16_t port, uint8_t data)
{
	asm volatile("outb %0, %1" : "=a"(data) : "d"(port));
}

void outw(uint16_t port, uint16_t data)
{
	asm volatile("outw %0, %1" : "=a"(data) : "d"(port));
}

void outl(uint16_t port, uint32_t data)
{
	asm volatile("outl %0, %1" : "=a"(data) : "d"(port));
}