#include "system.hpp"
#include "graphics.hpp"
#include "memory.hpp"
#include "io.hpp"

extern "C" void main() {

	// main os loop
	plotRect(0, 0, WIDTH, HEIGHT, BLUE);
	plotString(1, 1, "WELCOME TO OPERATING SYSTEM", WHITE);

	unsigned int one = (unsigned int)allocPage();
	unsigned int two = (unsigned int)allocPage();
	unsigned int three = (unsigned int)allocPage();
	freePage((void*)two);
	unsigned int four = (unsigned int)allocPage();
	unsigned int five = (unsigned int)allocPage();
	freePage((void*)one);
	unsigned int six = (unsigned int)allocPages(2);
	freePage((void*)four);
	unsigned int seven = (unsigned int)allocPages(2);
	freePage((void*)three);
	
	plotNumber(1, 20, one, WHITE);
	plotNumber(1, 30, two, WHITE);
	plotNumber(1, 40, three, WHITE);
	plotNumber(1, 50, four, YELLOW);
	plotNumber(1, 60, five, YELLOW);
	plotNumber(1, 70, six, RED);
	plotNumber(1, 80, seven, LIGHT_GREEN);

	void* diskbuffer = allocPages(2);

	for(int i = 0; i < 16; i++) {
		for(int j = 0; j < 32; j++) {
			plotNumber(100+j*5, 100+i*6, bitmap[i*32+j], LIGHT_CYAN);
		}
	}


	char* buf = (char*)allocPages(2);

	int inc = 0;
	int clock = 0;
	char c = 0;
	while(1) {
		clock++;
		plotRect(5, 190, 60, 5, BLUE);
		plotNumber(5, 190, clock, WHITE);

		// wait for keypress
		char key = keyToChar(keyPressed());
		if(key != c) {
			c = key;

			if(key != '\0') {
				buf[inc++] = c;

				plotRect(10, 10, 100, 5, BLUE);
				plotString(10, 10, buf, MAGENTA);
			}

			plotRect(200, 170, 100, 5, BLUE);
			plotNumber(200, 170, (char)keyPressed(), RED);


		}


	}
}