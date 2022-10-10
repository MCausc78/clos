#ifndef _KEYBOARD_DRIVER_H
#define _KEYBOARD_DRIVER_H
#include "sys/cpu/isr.h"

extern char key_buffer[];

void keyboard_callback(registers_t);

void init_keyboard(void);

#endif /* _KEYBOARD_DRIVER_H */
