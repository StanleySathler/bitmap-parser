#include <stdio.h>
#include <stdlib.h>
#include "bitmap.h"

int read_next_bytes(FILE *file, unsigned int bytes)
{
	int total = 0;

	for (unsigned int i = 0; i < bytes; i++) {
		total += (fgetc(file) << (8 * i));
	}

	return total;
}

void bitmap_parse(BitmapImage *pImage, FILE *file)
{
	int currentByte;
	long int cursor;

	while ((currentByte = fgetc(file)) != EOF) {
		cursor = ftell(file);

		if (cursor == 3)
			pImage->bfSize = currentByte + read_next_bytes(file, (DWORD - 1));

		else if (cursor == 11)
			pImage->bfOffBits = currentByte + read_next_bytes(file, (DWORD - 1));

		else if (cursor == 15)
			pImage->biSize = currentByte + read_next_bytes(file, (DWORD - 1));

		else if (cursor == 19)
			pImage->biWidth = currentByte + read_next_bytes(file, (LONG - 1));

		else if (cursor == 23)
			pImage->biHeight = currentByte + read_next_bytes(file, (LONG - 1));

		else if (cursor == 29)
			pImage->biBitCount = currentByte + read_next_bytes(file, (WORD - 1));

		else if (cursor == 35)
			pImage->biSizeImage = currentByte + read_next_bytes(file, (DWORD - 1));

		// content
		else if (cursor == (pImage->bfOffBits + 1)) {
			pImage->content = (unsigned char*) malloc(pImage->biSizeImage);
			pImage->content[0] = currentByte;

			for (unsigned int i = 1; i < pImage->biSizeImage; i++) {
				int byte = fgetc(file);
				pImage->content[i] = byte;
			}
		}
	}
}
