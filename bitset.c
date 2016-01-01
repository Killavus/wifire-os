#include "bitset.h"
#include "libkern.h"

void __bitset_printer_hex(WORD_TYPE* bf, size_t size){
    int i;
    for(i = size - 1; i >= 0; i--)
        kprintf("%0" STR(BITS_IN_BYTE) "x", bf[i]);
}

void __bitset_printer_bin(WORD_TYPE* bf, size_t size){
    int i, bit;
    for(i = size -1; i >= 0; i--){
        WORD_TYPE curr = bf[i];
        char bin[WORD_SIZE + 1];
        for(bit = 0; bit < WORD_SIZE; bit++){
            bin[WORD_SIZE - bit - 1] = (curr & 0x1)?'1':'0';
            curr /= 2;
        }
        bin[WORD_SIZE] = 0;
        kprintf("%s",bin);
    }
}