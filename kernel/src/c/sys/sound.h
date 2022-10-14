#ifndef _SYS_SOUND_H
#define _SYS_SOUND_H

#include <stdint.h>

void sys_sound_play(uint32_t);

void sys_sound_nosound();

void sys_sound_beep();

#endif /* _SYS_SOUND_H */