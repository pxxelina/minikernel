char *video = (char*)0xB8000;
int cursor = 0;

#define WHITE  0x07
#define GREEN  0x0A
#define YELLOW 0x0E
#define CYAN   0x0B
#define RED    0x04

void print_char(char c, char color) {
    if (c == 10) { cursor += (80 - (cursor % 80)); }
    else { video[cursor*2]=c; video[cursor*2+1]=color; cursor++; }
}

void print(char *str, char color) {
    for (int i = 0; str[i] != 0; i++) print_char(str[i], color);
}

void clear_screen() {
    for (int i = 0; i < 80*25; i++) { video[i*2]=32; video[i*2+1]=WHITE; }
    cursor = 0;
}

int strcmp(char *a, char *b) {
    int i=0; while(a[i]&&b[i]&&a[i]==b[i])i++; return a[i]-b[i];
}

unsigned char inb(unsigned short port) {
    unsigned char val;
    __asm__ volatile ("inb %1, %0":"=a"(val):"Nd"(port)); return val;
}

char read_key() {
    char keys[] = "??1234567890-=??qwertyuiop[]??asdfghjkl;~`?\\zxcvbnm,./? ?";
    unsigned char sc;
    do { while((inb(0x64)&0x01)==0); sc=inb(0x60); } while(sc&0x80);
    if(sc==0x1C) return 10; if(sc==0x0E) return 8; if(sc==0x39) return 32;
    if(sc<58) return keys[sc]; return 63;
}

void run_command(char *cmd) {
    if(strcmp(cmd,"help")==0){
        print("Available commands:\n",YELLOW);
        print("  help    - show commands\n",WHITE);
        print("  clear   - clear screen\n",WHITE);
        print("  version - kernel version\n",WHITE);
        print("  echo    - print text\n",WHITE);
    } else if(strcmp(cmd,"clear")==0){ clear_screen();
    } else if(strcmp(cmd,"version")==0){ print("MiniKernel v1.0\n",CYAN);
    } else if(cmd[0]==101&&cmd[1]==99&&cmd[2]==104&&cmd[3]==111&&cmd[4]==32){
        int i=5; while(cmd[i]) print_char(cmd[i++],WHITE); print_char(10,WHITE);
    } else { print("Unknown command. Type help\n",RED); }
}

void kernel_main() {
    clear_screen();
    print("Welcome to MiniKernel\n",GREEN);
    print("Type help for commands\n\n",WHITE);
    char input[80]; int len=0;
    while(1){
        print("> ",CYAN); len=0;
        while(1){
            char c=read_key();
            if(c==10){ print_char(10,WHITE); input[len]=0; break;}
            else if(c==8){ if(len>0){len--; cursor--; video[cursor*2]=32;}}
            else { input[len++]=c; print_char(c,WHITE);}
        }
        if(len>0) run_command(input);
    }
}
