#include "std/stdlib.h"
#include "std/string.h"
#include "sys/bitset.h"

bitset bitset_create() {
	bitset obj = { 0, 0 };
	return obj;
}

bool bitset_is_bit_enabled(bitset *bs, unsigned char key) {
	unsigned short *ptr;
	if(key < 32) {
		ptr = key > 16 ? &(bs->part2) : &(bs->part1);
		return ((*ptr) & (1 << (key % 16))) != 0;
	}
	return 0;
}

void bitset_set_bit(bitset *bs, unsigned char key, bool value) {
	unsigned short *ptr;
	if(key < 32) {
		ptr = key > 16 ? &(bs->part2) : &(bs->part1);
		unsigned int rs = (1 << (key % 16));
		if(value)
			*ptr |= rs;
		else if(bitset_is_bit_enabled(bs, key))
			*ptr &= ~rs;
	}
}

char *bitset_tostring(bitset *bs, char *buf) {
	char temp[16];
	ushort_tobinary(buf, bs->part1);
	strcat(buf, ushort_tobinary(temp, bs->part2));
	return buf;
}

unsigned int bitset_pack(bitset *bs) {
	unsigned int ui = 0;
	ui |= (((unsigned int)bs->part1));
	ui |= (((unsigned int)bs->part2) << 8);
	return ui;
}

bitset bitset_unpack(unsigned int i) {
	bitset bs = bitset_create();
	bs.part1 = (i & 0b0000000011111111);
	bs.part2 = ((i & 0b1111111100000000) >> 8);
	return bs;
}

unsigned char bitset_length(bitset *bs) {
	unsigned char bits;
	unsigned int part = bitset_pack(bs);
	for(bits = 0; part != 0; part >>= 1)
		if(part & 1)
			++bits;
	return bits;
}