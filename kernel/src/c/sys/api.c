#include <stdint.h>
#include "std/stdbool.h"
#include "sys/api.h"
#include "sys/ports.h"

void sleep(uint32_t t)
{
	while(--t > 0) asm volatile("nop");
}
