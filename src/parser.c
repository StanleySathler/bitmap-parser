#include <stdio.h>
#include <stdlib.h>
#include "bitmap.h"
#include "util.h"
#include "parser.h"

#define COLORS_PER_LINE 3
#define ERROR_MISSING_FILENAME 15

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

void print_content(BitmapImage *image)
{
	unsigned int bytes_per_pixel = (image->biBitCount / 8);
	unsigned int bytes_per_row = (bytes_per_pixel * image->biWidth);

	for (unsigned int i = 0; i < image->biSizeImage; i += bytes_per_pixel) {

		// if already printed all colors for current line
		if (is_multiple_of(bytes_per_row, i))
			putchar('\n');

		putchar('(');

		for (short int j = (bytes_per_pixel - 1); j >= 0; j--) {
			if (j < (bytes_per_pixel - 1))
				putchar(' ');

			printf("%02X", image->content[i + j]);
		}

		putchar(')');
	}

	putchar('\n');
}

void print_footer(BitmapImage *pImage)
{
	putchar('\n');
	printf("File size: ....................... %uB \n", pImage->bfSize);
	printf("Header length: ................... %uB \n", pImage->bfOffBits);
	printf("Width: ........................... %upx \n", pImage->biWidth);
	printf("Height: .......................... %upx \n", pImage->biHeight);
	printf("Color depth: ..................... %ub \n", pImage->biBitCount);
	printf("Content length: .................. %uB \n", pImage->biSizeImage);
}
