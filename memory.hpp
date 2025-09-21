extern volatile unsigned char* available_memory;
const unsigned int PAGE_SIZE = 4096;
const unsigned int BITMAP_SIZE = 512;
const unsigned int PAGE_TABLE_SIZE = 1024;

extern bool bitmap[BITMAP_SIZE];

void* alloc(unsigned int size);
void free(void* ptr);

void* allocPage();
void freePage(void* ptr);
void* allocPages(unsigned int count);
void freePages(void* ptr, unsigned int count);