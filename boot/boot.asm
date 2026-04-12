[BITS 32]
[GLOBAL start]
[EXTERN kernel_main]

MAGIC    equ 0x1BADB002
FLAGS    equ 0x0
CHECKSUM equ -(MAGIC + FLAGS)

section .multiboot
    dd MAGIC
    dd FLAGS
    dd CHECKSUM

section .text
start:
    call kernel_main
    hlt
