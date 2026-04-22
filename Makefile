CC = i686-elf-gcc
ASM = nasm
CFLAGS = -ffreestanding -O2 -Wall -Wextra

all: kernel.bin

boot/boot.o: boot/boot.asm
	$(ASM) -f elf32 boot/boot.asm -o boot/boot.o

drivers/display.o: drivers/display.c
	$(CC) $(CFLAGS) -c drivers/display.c -o drivers/display.o

drivers/keyboard.o: drivers/keyboard.c
	$(CC) $(CFLAGS) -c drivers/keyboard.c -o drivers/keyboard.o

lib/string.o: lib/string.c
	$(CC) $(CFLAGS) -c lib/string.c -o lib/string.o

kernel/shell.o: kernel/shell.c
	$(CC) $(CFLAGS) -c kernel/shell.c -o kernel/shell.o

kernel/kernel.o: kernel/kernel.c
	$(CC) $(CFLAGS) -c kernel/kernel.c -o kernel/kernel.o

kernel.bin: boot/boot.o drivers/display.o drivers/keyboard.o lib/string.o kernel/shell.o kernel/kernel.o
	$(CC) -T boot/linker.ld -o kernel.bin -ffreestanding -O2 -nostdlib boot/boot.o drivers/display.o drivers/keyboard.o lib/string.o kernel/shell.o kernel/kernel.o

run:
	qemu-system-i386 -kernel kernel.bin

clean:
	rm -f boot/boot.o drivers/display.o drivers/keyboard.o lib/string.o kernel/shell.o kernel/kernel.o kernel.bin
