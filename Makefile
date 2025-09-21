all:
	nasm -f bin boot.asm -o make/boot.bin

	nasm -f bin null.asm -o make/null.bin

	i686-elf-gcc -ffreestanding -m32 -c kernel.cpp -o make/kernel.o -Wall -Wextra -O2 -fno-exceptions -fno-rtti
	i686-elf-gcc -ffreestanding -m32 -c graphics.cpp -o make/graphics.o -Wall -Wextra -O2 -fno-exceptions -fno-rtti
	i686-elf-gcc -ffreestanding -m32 -c text.cpp -o make/text.o -Wall -Wextra -O2 -fno-exceptions -fno-rtti
	i686-elf-gcc -ffreestanding -m32 -c io.cpp -o make/io.o -Wall -Wextra -O2 -fno-exceptions -fno-rtti
	i686-elf-gcc -ffreestanding -m32 -c memory.cpp -o make/memory.o -Wall -Wextra -O2 -fno-exceptions -fno-rtti

	nasm -f elf kernel_entry.asm -o make/kernel_entry.o

	i686-elf-ld -o make/kernel.bin -Ttext 0x1000 make/kernel_entry.o make/kernel.o make/graphics.o make/text.o make/io.o make/memory.o --entry main --oformat binary 

	powershell -Command "Get-Content make/boot.bin, make/kernel.bin, make/null.bin -Raw | Set-Content image.bin -NoNewline"
	