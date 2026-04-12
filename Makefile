CC = i686-elf-gcc
ASM = nasm
CFLAGS = -ffreestanding -O2 -Wall -Wextra

all: kernel.bin

boot/boot.o: boot/boot.asm
	$(ASM) -f elf32 boot/boot.asm -o boot/boot.o

kernel/kernel.o: kernel/kernel.c
	$(CC) $(CFLAGS) -c kernel/kernel.c -o kernel/kernel.o

kernel.bin: boot/boot.o kernel/kernel.o
	$(CC) -T boot/linker.ld -o kernel.bin -ffreestanding -O2 -nostdlib boot/boot.o kernel/kernel.o

run:
	qemu-system-i386 -kernel kernel.bin

clean:
	rm -f boot/boot.o kernel/kernel.o kernel.bin
