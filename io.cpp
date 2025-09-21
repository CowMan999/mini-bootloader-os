#include "io.hpp"

void outb(unsigned short port, unsigned char val)
{
	asm volatile("outb %[data], %[ports]"
	                 :
	                 : [data] "a" (val), [ports] "Nd" (port));
}

unsigned char inb(unsigned short port)
{
    unsigned char input;

    asm volatile("inb %[ports], %[input]"
                 : [input] "=a" (input)
                 : [ports] "Nd" (port));

    return input;
}

unsigned short inw(unsigned short port)
{
    unsigned short input;

    asm volatile("inw %[ports], %[input]"
                 : [input] "=a" (input)
                 : [ports] "Nd" (port));

    return input;
}

void outw(unsigned short port, unsigned short val)
{
	asm volatile("outw %[data], %[ports]"
				 :
				 : [data] "a" (val), [ports] "Nd" (port));
				 
}

KeyScanCode keyPressed() {
	char c = inb(0x60);
	return static_cast<KeyScanCode>(c);
}

char keyToChar(KeyScanCode scanCode) {
    switch (scanCode) {
        case KeyScanCode::NONE: return '\0';
        case KeyScanCode::ESCAPE: return 27;
        case KeyScanCode::ONE: return '1';
        case KeyScanCode::TWO: return '2';
        case KeyScanCode::THREE: return '3';
        case KeyScanCode::FOUR: return '4';
        case KeyScanCode::FIVE: return '5';
        case KeyScanCode::SIX: return '6';
        case KeyScanCode::SEVEN: return '7';
        case KeyScanCode::EIGHT: return '8';
        case KeyScanCode::NINE: return '9';
        case KeyScanCode::ZERO: return '0';
        case KeyScanCode::MINUS: return '-';
        case KeyScanCode::EQUALS: return '=';
        case KeyScanCode::BACKSPACE: return '\b';
        case KeyScanCode::TAB: return '\t';
        case KeyScanCode::Q: return 'Q';
        case KeyScanCode::W: return 'W';
        case KeyScanCode::E: return 'E';
        case KeyScanCode::R: return 'R';
        case KeyScanCode::T: return 'T';
        case KeyScanCode::Y: return 'Y';
        case KeyScanCode::U: return 'U';
        case KeyScanCode::I: return 'I';
        case KeyScanCode::O: return 'O';
        case KeyScanCode::P: return 'P';
        case KeyScanCode::OPENBRACKET: return '[';
        case KeyScanCode::CLOSEBRACKET: return ']';
        case KeyScanCode::ENTER: return '\n';
        case KeyScanCode::LEFTCTRL: return '\0'; // Modify as needed
        case KeyScanCode::A: return 'A';
        case KeyScanCode::S: return 'S';
        case KeyScanCode::D: return 'D';
        case KeyScanCode::F: return 'F';
        case KeyScanCode::G: return 'G';
        case KeyScanCode::H: return 'H';
        case KeyScanCode::J: return 'J';
        case KeyScanCode::K: return 'K';
        case KeyScanCode::L: return 'L';
        case KeyScanCode::SEMICOLON: return ';';
        case KeyScanCode::APOSTROPHE: return '\'';
        case KeyScanCode::BACKTICK: return '`';
        case KeyScanCode::LEFTSHIFT: return '\0'; // Modify as needed
        case KeyScanCode::BACKSLASH: return '\\';
        case KeyScanCode::Z: return 'Z';
        case KeyScanCode::X: return 'X';
        case KeyScanCode::C: return 'C';
        case KeyScanCode::V: return 'V';
        case KeyScanCode::B: return 'B';
        case KeyScanCode::N: return 'N';
        case KeyScanCode::M: return 'M';
        case KeyScanCode::COMMA: return ',';
        case KeyScanCode::PERIOD: return '.';
        case KeyScanCode::SLASH: return '/';
        case KeyScanCode::RIGHTSHIFT: return '\0'; // Modify as needed
        case KeyScanCode::NUMPADMULTIPLY: return '*';
        case KeyScanCode::LEFTALT: return '\0'; // Modify as needed
        case KeyScanCode::SPACE: return ' ';
        case KeyScanCode::CAPSLOCK: return '\0'; // Modify as needed
        case KeyScanCode::F1: return '\0'; // Modify as needed
        case KeyScanCode::F2: return '\0'; // Modify as needed
        case KeyScanCode::F3: return '\0'; // Modify as needed
        case KeyScanCode::F4: return '\0'; // Modify as needed
        case KeyScanCode::F5: return '\0'; // Modify as needed
        case KeyScanCode::F6: return '\0'; // Modify as needed
        case KeyScanCode::F7: return '\0'; // Modify as needed
        case KeyScanCode::F8: return '\0'; // Modify as needed
        case KeyScanCode::F9: return '\0'; // Modify as needed
        case KeyScanCode::F10: return '\0'; // Modify as needed
        case KeyScanCode::NUMLOCK: return '\0'; // Modify as needed
        case KeyScanCode::SCROLLLOCK: return '\0'; // Modify as needed
        case KeyScanCode::NUMPAD7: return '7';
        case KeyScanCode::NUMPAD8: return '8';
        case KeyScanCode::NUMPAD9: return '9';
        case KeyScanCode::NUMPADMINUS: return '-';
        case KeyScanCode::NUMPAD4: return '4';
        case KeyScanCode::NUMPAD5: return '5';
        case KeyScanCode::NUMPAD6: return '6';
        case KeyScanCode::NUMPADPLUS: return '+';
        case KeyScanCode::NUMPAD1: return '1';
        case KeyScanCode::NUMPAD2: return '2';
        case KeyScanCode::NUMPAD3: return '3';
        case KeyScanCode::NUMPAD0: return '0';
        case KeyScanCode::NUMPADPERIOD: return '.';
        case KeyScanCode::F11: return '\0'; // Modify as needed
        case KeyScanCode::F12: return '\0'; // Modify as needed
        case KeyScanCode::HOME: return '\0'; // Modify as needed
        default: return '\0'; // Default case for unknown scan codes
    }
}