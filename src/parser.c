/*
 * Command: gcc -std=c99 -o parser parser.c bitmap.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "bitmap.h"

#define COLORS_PER_LINE 3
#define ERROR_MISSING_FILENAME 15

void print_content(BitmapImage *pImage);
void print_footer(BitmapImage *pImage);

int main(int argc, char **argv)
{
	FILE *bitmapFile;
	BitmapImage bitmapImage;

	if (argv[1] == 0) {
		printf("You must provide a file name: %s <filename> \n", argv[0]);
		exit(ERROR_MISSING_FILENAME);
	}

	bitmapFile = fopen(argv[1], "rb");
	bitmap_parse(&bitmapImage, bitmapFile);
	fclose(bitmapFile);

	putchar('\n');
	print_content(&bitmapImage);
	print_footer(&bitmapImage);
	putchar('\n');
	return 0;
}

void print_content(BitmapImage *pImage)
{
	unsigned int bytesPerPixel = (pImage->biBitCount / 8);

	// 0, 3, 6, 9 ...
	for (unsigned int i = 0; i < pImage->biSizeImage; i += bytesPerPixel) {
		putchar('(');

		// 0, 1, 2
		for (unsigned int j = (i + bytesPerPixel - 1); j < bytesPerPixel; j++) {
			// se i = 0, quero j = 2, 1, 0
			// se i = 3, quero j = 5, 4, 3
			// se i = 6, quero j = 8, 7, 6
			printf("%02X ", pImage->content[i - 1 - j]);
		}

		putchar(')');
	}

	/*
	for (unsigned int i = 1; i <= pImage->biSizeImage; i++) {
		if (((i - 1) % bytesPerPixel) == 0)
			putchar('(');

		printf("%02X ", pImage->content[i - 1]);

		if ((i % bytesPerPixel) == 0) {
			putchar('\b');
			putchar(')');
		}

		if ((i % (bytesPerPixel * pImage->biWidth)) == 0)
			putchar('\n');
	}
	*/
}

void print_footer(BitmapImage *pImage)
{
	puts("----------------------------------");
	printf("File size: ....................... %uB \n", pImage->bfSize);
	printf("Header length: ................... %uB \n", pImage->bfOffBits);
	printf("Width: ........................... %upx \n", pImage->biWidth);
	printf("Height: .......................... %upx \n", pImage->biHeight);
	printf("Color depth: ..................... %ub \n", pImage->biBitCount);
	printf("Content length: .................. %uB \n", pImage->biSizeImage);
}
