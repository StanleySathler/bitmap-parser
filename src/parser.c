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
	unsigned int curr_index = 0;

	for (int line = 0; line < image->biHeight; line++) {
		for (int column = 0; column <= image->biWidth; column++) {
			if (column == image->biWidth) {
				curr_index += bytes_per_pixel;
				continue;
			}

			putchar('(');
			for (int column_item_index = (bytes_per_pixel - 1); column_item_index >= 0; column_item_index--) {
				printf("%02X", image->content[curr_index + column_item_index]);

				if (column_item_index > 0)
					putchar(' ');
			}
			putchar(')');

			curr_index += bytes_per_pixel;
		}

		putchar('\n');
	}
	/*
	for (
		unsigned int cursor = 0, line = 1;
		cursor < image->biSizeImage;
		cursor += bytes_per_pixel
	) {
		if (cursor == (bytes_per_row * line) + ((line - 1) * bytes_per_pixel)) {
			line++;
			putchar('\n');
			continue;
		}

		putchar('(');

		for (short int j = (bytes_per_pixel - 1); j >= 0; j--) {
			if (j < (bytes_per_pixel - 1))
				putchar(' ');

			printf("%02X", image->content[cursor + j]);
		}

		putchar(')');
	}
	*/

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
