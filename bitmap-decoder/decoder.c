#include <stdio.h>

#define COLORS_PER_LINE 3
#define WORD 2
#define DWORD 4
#define LONG 4

typedef struct {
	unsigned int bfSize;
	unsigned int bfOffBits;
	unsigned int biWidth;
	unsigned int biHeight;
} BitmapImage;

void printFooter(BitmapImage *image);
void parse(BitmapImage *image, FILE *file);
int readBytes(FILE *file, unsigned int bytes);

int main(int argc, char **argv)
{
	FILE *bitmapFile;
	BitmapImage bitmapImage;

	bitmapFile = fopen(argv[1], "rb");
	parse(&bitmapImage, bitmapFile);
	fclose(bitmapFile);

	printFooter(&bitmapImage);
	return 0;
}

void printFooter(BitmapImage *image)
{
	putchar('\n');
	puts("--------------------------------------");
	printf("Header size: ..................... %uB \n", image->bfOffBits);
	printf("File size: ....................... %uB \n", image->bfSize);
	printf("Width: ........................... %upx \n", image->biWidth);
	printf("Height: .......................... %upx \n", image->biHeight);
	puts("--------------------------------------");
}

void parse(BitmapImage *image, FILE *file)
{
	int currentByte;
	long int cursor;

	while ((currentByte = fgetc(file)) != EOF) {
		cursor = ftell(file);

		// bfSize
		if (cursor == 3) {
			image->bfSize = currentByte;
		}

		// bfOffBits
		else if (cursor == 11) {
			image->bfOffBits = currentByte + readBytes(file, (DWORD - 1));
		}

		// bfWidth
		else if (cursor == 19) {
			image->biWidth = currentByte + readBytes(file, (LONG - 1));
		}

		else if (cursor == 23) {
			image->biHeight = currentByte + readBytes(file, (LONG - 1));
		}
	}
}

// int a[4] = {0x3a, 0x05, 0x00, 0x00}
// int total = (a[0]) + (a[1] << 8) + (a[2] << 16) + (a[3] << 24)
int readBytes(FILE *file, unsigned int bytes)
{
	int total = 0;

	for (unsigned int i = 0; i < bytes; i++) {
		total += (fgetc(file) << (8 * i));
	}

	return total;
}
