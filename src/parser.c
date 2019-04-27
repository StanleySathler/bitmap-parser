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
	int bytes_per_pixel = (image->biBitCount / 8);
	int bytes_per_row = (bytes_per_pixel * image->biWidth);
	int all_bytes_per_row = (bytes_per_row + bytes_per_pixel); // null break line byte

	for (int row = 0; row < image->biHeight; row++)
	{
		for (
			int	i = (image->biSizeImage - all_bytes_per_row * (row + 1));
			i < (image->biSizeImage - (all_bytes_per_row * row) - bytes_per_pixel);
			i += bytes_per_pixel
		)
		{
			putchar('(');
			for (int j = (i + (bytes_per_pixel - 1)); j >= i; j--)
				printf("%02X", image->content[j]);
			putchar(')');
		}

		putchar('\n');
	}
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
