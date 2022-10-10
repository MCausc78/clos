#include <stdint.h>
#include "std/bool.h"
#include "sys/api.h"
#include "sys/ports.h"

void sleep(uint32_t time)
{
	uint32_t t=time;
	while(--t <= 0) asm volatile("nop");
}
