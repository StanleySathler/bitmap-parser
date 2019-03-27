#include <stdio.h>

#define COLORS_PER_LINE 3

typedef struct {
	unsigned int size;
	unsigned int headerSize;
	unsigned int width;
	unsigned int height;
} BitmapImage;

void printFooter(BitmapImage *image);
void parse(BitmapImage *image, FILE *file);

int main(void)
{
	FILE *bitmapFile;
	BitmapImage bitmapImage;

	bitmapFile = fopen("/home/stanley/Desktop/x.bmp", "rb");
	parse(&bitmapImage, bitmapFile);
	fclose(bitmapFile);

	printFooter(&bitmapImage);
	return 0;
}

void printFooter(BitmapImage *image)
{
	putchar('\n');
	puts("--------------------------------------");
	printf("Header in bytes: ..................... %uB \n", image->headerSize);
	printf("Total in bytes: ...................... %uB \n", image->size);
	putchar('\n');
}

void parse(BitmapImage *image, FILE *file)
{
	int currentByte;
	unsigned short int cursor = 0;

	while ((currentByte = fgetc(file)) != EOF) {
		cursor++;

		// bfSize
		if (cursor == 3) {
			image->size = currentByte;
		}

		// bfOffBits
		else if (cursor == 11) { // must read whole DWORD (4B)
			image->headerSize = currentByte;
		}
	}
}
