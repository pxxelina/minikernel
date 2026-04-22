#include "../include/display.h"
#include "../include/keyboard.h"
#include "../include/shell.h"

void kernel_main() {
    clear_screen();
    print("Welcome to MiniKernel\n", GREEN);
    print("Type help for commands\n\n", WHITE);

    char input[80];
    int len = 0;

    while (1) {
        print("> ", CYAN);
        len = 0;
        while (1) {
            char c = read_key();
            if (c == 10) {
                print_char(10, WHITE);
                input[len] = 0;
                break;
            } else if (c == 8) {
                if (len > 0) { len--; cursor--; video[cursor*2] = 32; }
            } else {
                input[len++] = c;
                print_char(c, WHITE);
            }
        }
        if (len > 0) run_command(input);
    }
}
