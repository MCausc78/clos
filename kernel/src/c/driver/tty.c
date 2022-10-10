#include "driver/tty.h"
#include "driver/vga.h"
#include "std/string.h"
#include "sys/sound.h"

#include <stddef.h>
#include <stdint.h>

size_t row;
size_t col;
uint8_t term_color;
uint16_t* term_buf;

void set_default_color(void) {
	//term_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	term_color = vga_entry_color(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
}

void set_row(size_t nrow) {
	row = nrow;
}

void set_col(size_t ncol) {
	col = ncol;
}

void clear(void) {
	row = 0;
	col = 0;
	term_buf = (uint16_t*) 0xB8000;
	for(size_t y = 0; y < VGA_HEIGHT; y++)
		for(size_t x = 0; x < VGA_WIDTH; x++)
			putchar_at(' ', x, y);
}

void tty_scroll(void) {
	memmove(term_buf, term_buf + VGA_WIDTH, VGA_WIDTH * (VGA_HEIGHT - 1) * sizeof(uint16_t));
	size_t index = (VGA_HEIGHT - 1) * VGA_WIDTH;
	for(size_t x = 0; x < VGA_WIDTH; ++x)
		term_buf[index + x] = vga_entry(' ', term_color);
	--row;
}

void tty_setcolor(uint8_t color) {
	term_color = color;
}

void putcchar_at(char c, uint8_t color, size_t x, size_t y) 
{
	if(c == '\a' || c == '\b' || c == 'f' || c == '\n' || c == '\r') return;
	term_buf[(vga_get_index(x, y))] = vga_entry(c, color);
}

void putchar_at(char c, size_t x, size_t y) {
	putcchar_at(c, term_color, x, y);
}

void putchar(char c) 
{
	unsigned char uc = c;
	putchar_at(uc, col, row);
	if(++col == VGA_WIDTH) {
		col = 0;
		if (++row == VGA_HEIGHT)
			tty_scroll();
	}
	// сначала проверка на управляющий символ, так мы не отобразим странные символы ASCII
	// также, мы их реализуем!
	switch(uc) {
		case '\a':
			beep();
			col--;
			break;
		case '\b':
			if(col > 1)
				col -= 2;
			break;
		case '\t':
			// 4 раза
			for(int i=0; i<5; i++)
				putchar(' ');
			break;
		case '\n':
			// новая строка
			col = 0;
			row++;
			break;
		case '\f':
			clear();
			break;
		case '\r':
			col = 0;
			break;
	}
}

void putcchar(char c, uint8_t color) {
	uint8_t oc = term_color + 0;
	tty_setcolor(color);
	putchar(c);
	tty_setcolor(oc);
}

/*
switch(ch) {
case 11:
	if(row < VGA_HEIGHT) row++; break;
case 24:
	if(col > 0) col--; break
case 25:
	if(col < VGA_WIDTH) col++; break;
case 26:
	if(row > 0) row--; break;
case 28:
	row = VGA_HEIGHT - 1; col = 0;
	break;
case 29:
	row = 0; col = 0;
	break;
case 30:
	for(size_t c = col; c < VGA_WIDTH; c++)
		putchar_at(' ', c, row);
	break;
case 31:
	for(size_t r = row; r < VGA_HEIGHT; row++, r++)
		putchar(30);
	break;
*/