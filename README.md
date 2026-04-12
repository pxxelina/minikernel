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

---

## 🛠️ Tools used

| Tool | What it does |
|------|---------|
| i686-elf-gcc | compiles the C code |
| nasm | handles the boot assembly code |
| qemu-system-i386 | runs and tests the kernel |
| make | automates the build process |

---

## 🚀 How to run it

compile it:
make

launch it:
make run

once it starts you will see:
Welcome to MiniKernel
Type help for commands

---

## 💻 Shell commands

| Command | What it does |
|---------|-------------|
| help | shows all available commands |
| clear | clears the screen |
| version | shows the kernel version |
| echo text | prints whatever you type |

---

## 🌈 Colors

| Color | Used for |
|-------|---------|
| Green | welcome message |
| Cyan | prompt and version |
| Yellow | help command |
| Red | error messages |
| White | normal text |

---

## 📁 Project structure

minikernel/
- boot/        kernel startup code in Assembly 🔧
- kernel/      main kernel logic in C ⚙️
- drivers/     keyboard driver ⌨️
- lib/         helper functions 📚
- include/     header files 📋
- Makefile     build automation 🔨
- README.md    you are reading it right now 📝

---

## 🌿 Git workflow

- main              stable final version ✅
- develop           main development branch 🔨
- feature/boot      boot code 🥾
- feature/display   display functions 🖥️
- feature/keyboard  keyboard driver ⌨️
- feature/shell     mini shell 🐚
- feature/colors    colored terminal 🌈
- feature/makefile  build system 🔨
- feature/readme    documentation 📝

---

## 👩‍💻 Author

Yassire Lina 🌸
Challenges Track 2026 ❤️
