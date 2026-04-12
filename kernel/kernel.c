char *video = (char*)0xB8000;
int cursor = 0;

void print_char(char c, char color) {
    if (c == 10) {
        cursor += (80 - (cursor % 80));
    } else {
        video[cursor * 2] = c;
        video[cursor * 2 + 1] = color;
        cursor++;
    }
}

void print(char *str, char color) {
    for (int i = 0; str[i] != 0; i++)
        print_char(str[i], color);
}

void clear_screen() {
    for (int i = 0; i < 80 * 25; i++) {
        video[i * 2] = 32;
        video[i * 2 + 1] = 0x07;
    }
    cursor = 0;
}

void kernel_main() {
    clear_screen();
    print("Welcome to MiniKernel", 0x0A);
    while(1);
}
