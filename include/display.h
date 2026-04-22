#ifndef DISPLAY_H
#define DISPLAY_H

#define WHITE  0x07
#define GREEN  0x0A
#define YELLOW 0x0E
#define CYAN   0x0B
#define RED    0x04

void print_char(char c, char color);
void print(char *str, char color);
void clear_screen();

#endif

extern char *video;
extern int cursor;
