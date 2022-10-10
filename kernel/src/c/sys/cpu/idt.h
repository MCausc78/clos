#ifndef _SYS_CPU_IDT_H
#define _SYS_CPU_IDT_H

#define KERNEL_CS 0x08

typedef struct {
	unsigned short low_offset;
	unsigned short sel;
	unsigned char always0;
	unsigned char flags;
	unsigned short high_offset;
} __attribute__((packed)) idt_gate_t;

typedef struct {
	unsigned short limit;
	unsigned int base;
} __attribute__((packed)) idt_register_t;

#define IDT_ENTRIES 256
/*extern */idt_gate_t idt[IDT_ENTRIES];
/*extern */idt_register_t idt_reg;

void set_idt_gate(int, unsigned int);
void set_idt(void);

#endif /* _SYS_CPU_IDT_H */