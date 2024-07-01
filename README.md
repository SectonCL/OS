# SCL OS
(Experimental) SCL in an OS

This is an OS that can run Python code, in our case it's SCL.

## Compilation on Linux

(keep in mind this is the first time i'm writing an compile instructions)

Requirements: `nasm gcc python3-dev` and other stuff (sorry, but as i said this is my first time writing compile instructions)

1. Assembly: `nasm -f elf64 kernel.asm -o kasm.o`
2. GCC: `gcc -I/usr/include/python3.12 -m64 -c kernel.c -o kc.o`
3. Linker: `echo Not Done yet!` I haven't figured how to make it work, but if you might want to help, then here's the command that's not working: `ld -T link.ld -melf_x86_64 -o kernel kasm.o kc.o`

## Testing on Linux

1. Install `qemu-system-x86`
2. run `qemu-system-x86 -kernel kernel` in the same folder where you got *.o files

## Things to come

- [ ] New Compile directory
- [ ] Fully Tested and Working SCL
- [ ] Special commands for SCL OS (Probably will be ported to executable version later)
