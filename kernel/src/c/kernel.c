#include "kernel.h"

#include "driver/tty.h"
#include "driver/vga.h"
#include "std/io.h"
#include "std/stdlib.h"
#include "sys/bitset.h"

void main(void) {
	tty_setcolor(vga_entry_color(VGA_COLOR_WHITE, VGA_COLOR_RED));
	clear();
	row = 0;
	col = 0;
}

void got_input(char *txt) {
}