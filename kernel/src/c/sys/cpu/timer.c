#include "sys/cpu/timer.h"
#include "sys/cpu/isr.h"
#include "sys/ports.h"

unsigned int tick = 0;

void timer_callback(registers_t regs) {
	tick++;
	(void)(regs);
}

void init_timer(unsigned int freq) {
	register_interrupt_handler(IRQ0, timer_callback);
	unsigned int divisor = 1193180 / freq;
	unsigned char low  = (unsigned char)(divisor & 0xFF);
	unsigned char high = (unsigned char)((divisor >> 8) & 0xFF);
	/* Send the command */
	outb(0x43, 0x36);
	outb(0x40, low);
	outb(0x40, high);
}