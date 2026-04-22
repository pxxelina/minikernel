#include "../include/shell.h"
#include "../include/display.h"
#include "../include/string.h"

void run_command(char *cmd) {
    if (strcmp(cmd, "help") == 0) {
        print("Available commands:\n", YELLOW);
        print("  help    - show commands\n", WHITE);
        print("  clear   - clear screen\n", WHITE);
        print("  version - kernel version\n", WHITE);
        print("  echo    - print text\n", WHITE);
    } else if (strcmp(cmd, "clear") == 0) {
        clear_screen();
    } else if (strcmp(cmd, "version") == 0) {
        print("MiniKernel v1.0\n", CYAN);
    } else if (cmd[0]=='e' && cmd[1]=='c' && cmd[2]=='h' && cmd[3]=='o' && cmd[4]==' ') {
        int i = 5;
        while (cmd[i]) print_char(cmd[i++], WHITE);
        print_char(10, WHITE);
    } else {
        print("Unknown command. Type help\n", RED);
    }
}
