#include "../include/keyboard.h"

unsigned char inb(unsigned short port) {
    unsigned char val;
    __asm__ volatile ("inb %1, %0":"=a"(val):"Nd"(port));
    return val;
}

char read_key() {
    char keys[] = "??1234567890-=??qwertyuiop[]??asdfghjkl;~`?\\zxcvbnm,./? ?";
    unsigned char sc;
    do { while((inb(0x64)&0x01)==0); sc=inb(0x60); } while(sc&0x80);
    if (sc == 0x1C) return 10;
    if (sc == 0x0E) return 8;
    if (sc == 0x39) return 32;
    if (sc < 58) return keys[sc];
    return 63;
}
