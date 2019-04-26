#include <stdio.h>
#include <stdlib.h>
#include "bitmap.h"
#include "util.h"
#include "parser.h"

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

	/* First group of bytes */
	putchar('(');
	printf("%02X", image->content[26]);
	printf("%02X", image->content[25]);
	printf("%02X", image->content[24]);
	putchar(')');

	/* Second group of bytes */
	putchar('(');
	printf("%02X", image->content[29]);
	printf("%02X", image->content[28]);
	printf("%02X", image->content[27]);
	putchar(')');

	/* Third group of bytes */
	putchar('(');
	printf("%02X", image->content[32]);
	printf("%02X", image->content[31]);
	printf("%02X", image->content[30]);
	putchar(')');

	/* Forth group of bytes */
	/* Break-line bytes - should be ignored */
	putchar('\n');

	/* Fifth group of bytes */
	putchar('(');
	printf("%02X", image->content[14]);
	printf("%02X", image->content[13]);
	printf("%02X", image->content[12]);
	putchar(')');

	/* Sixth group of bytes */
	putchar('(');
	printf("%02X", image->content[17]);
	printf("%02X", image->content[16]);
	printf("%02X", image->content[15]);
	putchar(')');

	/* Seventh group of bytes */
	putchar('(');
	printf("%02X", image->content[20]);
	printf("%02X", image->content[19]);
	printf("%02X", image->content[18]);
	putchar(')');

	// for (int line = (image->biHeight - 1); line >= 0; line--) {
	// 	for (unsigned int column = 0; column <= image->biWidth; column++) {
	// 		if (column == image->biWidth) {
	// 			curr_index += bytes_per_pixel;
	// 			continue;
	// 		}

	// 		putchar('(');
	// 		for (int short column_item_index = (bytes_per_pixel - 1); column_item_index >= 0; column_item_index--) {
	// 			printf("%02X", image->content[curr_index + column_item_index]);

	// 			if (column_item_index > 0)
	// 				putchar(' ');
	// 		}
	// 		putchar(')');

	// 		curr_index += bytes_per_pixel;
	// 	}

	// 	putchar('\n');
	// }

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
