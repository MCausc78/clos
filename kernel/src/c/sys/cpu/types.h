#ifndef _SYS_CPU_TYPES_H
#define _SYS_CPU_TYPES_H

/*extern unsigned char high_16(unsigned char);
extern unsigned char low_16(unsigned char);*/

#define low_16(address) (unsigned char)((address) & 0xFFFF)
#define high_16(address) (unsigned char)(((address) >> 16) & 0xFFFF)

#endif /* _SYS_CPU_TYPES_H */