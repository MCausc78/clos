#include "sys/sound.h"

#include <stdint.h>
#include "sys/ports.h"

void playSound(uint32_t frequence) {
	uint32_t div = 1193180 / frequence;
	
	outb(0x43, 0xb6);
	outb(0x42, (uint8_t)(div));
	outb(0x42, (uint8_t)(div >> 8));
	
	uint8_t tmp = inb(0x61);
	
	if (tmp != (tmp | 3)) {
		outb(0x61, tmp | 3);
	}
}

void noSound() {
	outb(0x61, inb(0x61) & 0xFC);
}

void beep() {
	playSound(100);
	noSound();
}