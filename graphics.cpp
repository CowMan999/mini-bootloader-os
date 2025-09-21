#include "graphics.hpp"

volatile unsigned char* text_video_memory = (unsigned char*) 0xb8000;
volatile unsigned char* video_memory = (unsigned char*) 0xA0000;

const unsigned int WIDTH = 320;
const unsigned int HEIGHT = 200;

void plotPixel(int x, int y, Color color) {
	*(video_memory + x + y*WIDTH) = color;
}

void plotRect(int x, int y, int width, int height, Color color) {
	for(int i = 0; i < width; i++) {
		for(int j = 0; j < height; j++) {
			plotPixel(x+i, y+j, color);
		}
	}
}

void plotChar(int x, int y, char c, Color color) {

	// 4x5 font
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 4; j++) {
			
			if(c > 9) {
				if(pixel4x5font[c - 'A'][i][j]) {
					plotPixel(x+j, y+i, color);
				}
			} else {
				if(pixel4x5fontnumbers[(int)c][i][j]) {
					plotPixel(x+j, y+i, color);
				}
			}
		}
	}
}

void plotString(int x, int y, const char* c, Color color) {
	int i = 0;
	int off = 0;
	while(c[i] != '\0') {
		if(c[i] != ' ' && c[i] != '\n') {
			if(c[i] >= 'A')
				plotChar(x + i*4 + i - off, y, c[i], color);
			else if(c[i] >= '0')
				plotChar(x + i*4 + i - off, y, c[i] - '0', color);
		} else if(c[i] == '\n') {
			y += 6;
			off = (i+1)*4 + (i+1);
		}
		i++;
	}
}

void plotNumber(int x, int y, int num, Color color) {

	if(num == 0) {
		plotChar(x, y, 0, color);
		return;
	}
	
	int i = 0;
	int digits = 0;
	int temp = num;
	while (temp != 0) {
		temp /= 10;
		digits++;
	}

	x += digits*4 + digits;

	while (num != 0) {
		plotChar(x - (i*4 + i) - 4, y, (num % 10), color);
		num /= 10;
		i++;
	}
}