# MiniKernel 🖥️

a small but powerful operating system kernel built from scratch in C and Assembly 🎉

---

## 🤔 What is MiniKernel?

MiniKernel is a kernel inspired by Unix and Linux.
it boots inside QEMU and comes with a working shell where you can type and run commands.
it covers everything from the boot process to keyboard input, colored output and command execution.

---

## 🎨 Features

- colored terminal output 🌈
- working shell with multiple commands
- real keyboard input
- boots from scratch in QEMU
- modular code structure with separate drivers and libraries

---

## 📁 Project structure

```
minikernel/
├── boot/
│   ├── boot.asm       the entry point written in Assembly
│   └── linker.ld      tells the linker how to organize memory
├── kernel/
│   ├── kernel.c       the main kernel entry point
│   └── shell.c        reads commands and executes them
├── drivers/
│   ├── display.c      handles printing text and colors on screen
│   └── keyboard.c     reads key presses from the keyboard
├── lib/
│   └── string.c       helper string functions like strcmp
├── include/
│   ├── display.h      header for display functions
│   ├── keyboard.h     header for keyboard functions
│   ├── shell.h        header for shell functions
│   └── string.h       header for string functions
├── Makefile           automates the build process
└── README.md          you are reading it right now 📝
```

---

## 🛠️ Tools you need

| Tool | What it does |
|------|-------------|
| i686-elf-gcc | cross compiler for 32 bit x86 |
| nasm | assembles the boot code |
| qemu-system-i386 | runs the kernel in a virtual machine |
| make | automates compilation |

---

## ⚙️ How to install the tools

on macOS:
```bash
brew install i686-elf-gcc nasm qemu
```

on Ubuntu / Debian:
```bash
sudo apt install nasm qemu-system-x86
```

for i686-elf-gcc on Linux you need to build it from source or use a prebuilt cross compiler toolchain.

---

## 🚀 How to build and run

clone the repo:
```bash
git clone https://github.com/Lina-Yassire/minikernel.git
cd minikernel
```

compile everything:
```bash
make
```

run it in QEMU:
```bash
make run
```

clean compiled files:
```bash
make clean
```

once it starts you will see:
```
Welcome to MiniKernel
Type help for commands

>
```

---

## 💻 Shell commands

| Command | What it does |
|---------|-------------|
| help | shows all available commands |
| clear | clears the screen |
| version | shows the kernel version |
| echo text | prints whatever you type after echo |

---

## 🌈 Colors

| Color | Used for |
|-------|---------|
| Green | welcome message |
| Cyan | prompt and version |
| Yellow | help command output |
| Red | error messages |
| White | normal text |

---

## 🌿 Git workflow

| Branch | Purpose |
|--------|---------|
| main | stable final version |
| develop | main development branch |
| feature/boot | boot code |
| feature/display | display functions |
| feature/keyboard | keyboard driver |
| feature/shell | mini shell |
| feature/colors | colored terminal |
| feature/makefile | build system |
| feature/readme | documentation |

---

## 👩‍💻 Author

Yassire Lina 🌸
Challenges Track 2026 ❤️
