[org 0x7c00]

KERNEL equ 0x1000


xor ax, ax
mov ds, ax
mov es, ax
mov bp, 0x8000
mov sp, bp

mov bx, KERNEL
mov dh, 35 ; read all kernel sectors

mov ah, 0x02
mov al, dh
mov ch, 0x00
mov cl, 0x02
mov dh, 0x00
int 0x13 ; load

;mov ah, 0x00
;mov al, 0x03
;int 0x10 ; set text mode and clear screen

mov ah, 0x00
mov al, 0x13
int 0x10 ; graphics mode baby

CODE_SEG equ code - GDT_START
DATA_SEG equ data - GDT_START

cli

lgdt [GDT_POINTER]

mov eax, cr0
or eax, 0x1
mov cr0, eax ; 32 bit

; mega jump
jmp CODE_SEG:protected_mode

jmp $

GDT_START:
	null: ; simple enough
		dd 0x00000000
		dd 0x00000000
	code:
		dw 0xffff ; limit low, first 16 bits
		dw 0x0000 ; base low, first 16 bits
		db 0x00 ; base middle, next 8 bits
		db 0b10011010 ; access flags, present, privlege 0, type code, executable, readable
		db 0b11001111 ; granularity, 32 bit, 4k pages, limit high, last 4 bits
		db 0x00 ; base high, last 8 bits
	data:
		dw 0xffff ; limit low, first 16 bits
		dw 0x0000 ; base low, first 16 bits
		db 0x00 ; base middle, next 8 bits
		db 0b10010010 ; access flags, present, privlege 0, type data, writable
		db 0b11001111 ; granularity, 32 bit, 4k pages, limit high, last 4 bits
		db 0x00 ; base high, last 8 bits
	GDT_END:

GDT_POINTER:
	dw GDT_END - GDT_START - 1
	dd GDT_START

[bits 32]
protected_mode: ; we jumped all the way here
	mov ax, DATA_SEG
	mov ds, ax
	mov ss, ax
	mov es, ax ; set all segment registers to data segment for simplicity
	mov fs, ax
	mov gs, ax
	mov ebp, 0x90000 ; set stack pointer to 0x90000
	mov esp, ebp

	jmp KERNEL ; jump to kernel


times 510-($-$$) db 0
db 0x55, 0xaa