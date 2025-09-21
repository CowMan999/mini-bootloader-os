#include "text.hpp"

extern volatile unsigned char* text_video_memory;
extern volatile unsigned char* video_memory;

extern const unsigned int WIDTH;
extern const unsigned int HEIGHT;

enum Color {
	BLACK = 0,
	BLUE = 1,
	GREEN = 2,
	CYAN = 3,
	RED = 4,
	MAGENTA = 5,
	BROWN = 6,
	LIGHT_GRAY = 7,
	DARK_GRAY = 8,
	LIGHT_BLUE = 9,
	LIGHT_GREEN = 10,
	LIGHT_CYAN = 11,
	LIGHT_RED = 12,
	LIGHT_MAGENTA = 13,
	YELLOW = 14,
	WHITE = 15
};


void plotPixel(int x, int y, Color color);
void plotRect(int x, int y, int width, int height, Color color);
void plotChar(int x, int y, char c, Color color);
void plotString(int x, int y, const char* c, Color color);
void plotNumber(int x, int y, int num, Color color);