#define WORD 2
#define DWORD 4
#define LONG 4

typedef struct {
	unsigned int bfSize;
	unsigned int bfOffBits;
	unsigned int biSize;
	unsigned int biWidth;
	unsigned int biHeight;
	unsigned int biBitCount;
	unsigned int biSizeImage;
	unsigned char* content;
} BitmapImage;

void bitmap_parse(BitmapImage *pImage, FILE *file);
int read_next_bytes(FILE *file, unsigned int bytes);
