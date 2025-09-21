#include "memory.hpp"

volatile unsigned char* available_memory = (unsigned char*)0x100000;
unsigned int memory_pos = 0;

bool bitmap[BITMAP_SIZE] = {0};

void* allocPage() {
	for (unsigned int i = memory_pos; i < BITMAP_SIZE; i++) {
		if (bitmap[i] == 0) {
			bitmap[i] = 1;
			memory_pos = i;
			return (void*)(available_memory + i * PAGE_SIZE);
		}
	}
	return nullptr;
}


void* allocPages(unsigned int count) {
	for (unsigned int i = memory_pos; i < (BITMAP_SIZE - count) + 1; i++) {

		bool available = true;
		for(unsigned int j = i; j < i + count; j++) {
			if(bitmap[j] == 1) {
				available = false;
				break;
			}
		}

		if(available) {
			for(unsigned int j = i; j < i + count; j++) {
				bitmap[j] = 1;
			}

			return (void*)(available_memory + i * PAGE_SIZE);
		}
	}
	return nullptr;
}

void freePage(void* ptr) {
	unsigned int index = ((unsigned int)ptr - (unsigned int)available_memory) / PAGE_SIZE;
	bitmap[index] = 0;
	if(index < memory_pos) memory_pos = index;
}

void freePages(void* ptr, unsigned int count) {
	unsigned int index = ((unsigned int)ptr - (unsigned int)available_memory) / PAGE_SIZE;
	for (unsigned int i = index; i < index + count; i++) {
		bitmap[i] = 0;
	}
	
	if(index < memory_pos) memory_pos = index;
}