struct idt_entry
{
    unsigned short base_lo;
    unsigned short sel;
    unsigned char always0; 
    unsigned char flags;
    unsigned short base_hi;
} __attribute__((packed));

struct idt_ptr
{
    unsigned short limit;
    unsigned int base;
} __attribute__((packed));

// idt of length 256
__attribute__((aligned(0x10))) struct idt_entry idt[256];
struct idt_ptr idtp;

void idt_load() {
	// i386 architecture
	asm ("lidt (%0)" : : "r" (&idtp));
}

void exception_handler() {
    asm volatile ("cli; hlt"); // Completely hangs the computer
}

void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags)
{
    // set base
	idt[num].base_lo = (base & 0xFFFF);
	idt[num].base_hi = (base >> 16) & 0xFFFF;

	// set selector
	idt[num].sel = sel;

	// other flags
	idt[num].always0 = 0;
	idt[num].flags = flags;
}

void idt_install()
{
    // set idt pointer
    idtp.limit = (sizeof (struct idt_entry) * 256) - 1;
    idtp.base = (unsigned int)&idt;

	// clear idt
    for(int i = 0; i < 256; i++) {
		idt[i].base_lo = 0;
		idt[i].base_hi = 0;
		idt[i].always0 = 0;
		idt[i].flags = 0;
		idt[i].sel = 0;
	}

    // load idt
    idt_load();
}