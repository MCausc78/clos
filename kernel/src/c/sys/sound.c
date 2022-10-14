#include "sys/sound.h"

#include <stdint.h>
#include "sys/ports.h"

void sys_sound_play(uint32_t frequence) {
	uint32_t div = 1193180 / frequence;
	
	outb(0x43, 0xb6);
	outb(0x42, (uint8_t)(div));
	outb(0x42, (uint8_t)(div >> 8));
	
	uint8_t tmp = inb(0x61);
	
	if (tmp != (tmp | 3)) {
		outb(0x61, tmp | 3);
	}
}

void sys_sound_nosound() {
	outb(0x61, inb(0x61) & 0xFC);
}

void sys_sound_beep() {
	sys_sound_play(100);
	sys_sound_nosound();
}