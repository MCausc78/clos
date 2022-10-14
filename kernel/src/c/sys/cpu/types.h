#ifndef _SYS_CPU_TYPES_H
#define _SYS_CPU_TYPES_H

#define low_16(address) (unsigned char)((address) & 0xFFFF)
#define high_16(address) (unsigned char)(((address) >> 16) & 0xFFFF)

#endif /* _SYS_CPU_TYPES_H */