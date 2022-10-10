#include "driver/keyboard.h"
#include "driver/tty.h"
#include "std/io.h"
#include "std/string.h"
#include "sys/cpu/isr.h"
#include "sys/ports.h"
#include "kernel.h"

#define BACKSPACE 0x0E
#define ENTER 0x1C

char key_buffer[256];

#define SC_MAX 57
const char *sc_name[] = { "???", "Esc", "1", "2", "3", "4", "5", "6", 
	"7", "8", "9", "0", "-", "=", "Backspace", "Tab", "Q", "W", "E", 
		"R", "T", "Y", "U", "I", "O", "P", "[", "]", "Enter", "Lctrl", 
		"A", "S", "D", "F", "G", "H", "J", "K", "L", ";", "'", "`", 
		"LShift", "\\", "Z", "X", "C", "V", "B", "N", "M", ",", ".", 
		"/", "RShift", "Keypad *", "LAlt", "Spacebar"};
const char sc_ascii[] = { '?', '?', '1', '2', '3', '4', '5', '6',     
	'7', '8', '9', '0', '-', '=', '?', '?', 'Q', 'W', 'E', 'R', 'T', 'Y', 
		'U', 'I', 'O', 'P', '[', ']', '?', '?', 'A', 'S', 'D', 'F', 'G', 
		'H', 'J', 'K', 'L', ';', '\'', '`', '?', '\\', 'Z', 'X', 'C', 'V', 
		'B', 'N', 'M', ',', '.', '/', '?', '?', '?', ' '};

void keyboard_callback(registers_t regs) {
	unsigned char scancode = inb(0x60);
	
	if (scancode > SC_MAX) return;
	if (scancode == BACKSPACE) {
		string_delete_last(key_buffer);
		printf("\b \b");
	} else if (scancode == ENTER) {
		putchar('\n');
		got_input(key_buffer);
		key_buffer[0] = '\0';
	} else {
		char letter = sc_ascii[(int)scancode];
		string_append(key_buffer, letter);
		putchar(letter);
	}
	(void)(regs);
}

void init_keyboard(void) {
   register_interrupt_handler(IRQ1, keyboard_callback); 
}