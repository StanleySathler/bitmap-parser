#include <stdio.h>

#define COLORS_PER_LINE 3

typedef struct {
	unsigned int size;
	unsigned int headerSize;
} BitmapImage;

void printGroupedColors();

int main(void)
{
	FILE *bitmapFile;
	BitmapImage bitmapImage;
	unsigned short int content[1024];
	unsigned short int columnCursor = 0;
	unsigned short int colorsCursor = 0;
	unsigned int currentByte = 0;
	unsigned int readBytes = 0;

	bitmapFile = fopen("/home/stanley/Desktop/x.bmp", "rb");

	for ((currentByte = fgetc(bitmapFile)); currentByte != EOF; (currentByte = fgetc(bitmapFile)), readBytes++) {
		content[readBytes] = currentByte;

		// header has started
		if (readBytes <= 54) {
			if (readBytes == 0) {
				puts("Header: ");
				columnCursor = 0;
			}

			if (columnCursor == 0) {
				putchar('[');
			}

			printf("%02X", currentByte);

			columnCursor++;

			if (columnCursor == 3 || readBytes == 54) {
				colorsCursor++;
				columnCursor = 0;
				printf("] ");
			}

			if (readBytes == 54 || colorsCursor == COLORS_PER_LINE) {
				colorsCursor = 0;
				putchar('\n');
			}
		}

		// bfSize
		if (readBytes == 2) {
			bitmapImage.size = currentByte;
		}

		// bfOffBits
		else if (readBytes == 10) {
			bitmapImage.headerSize = currentByte;
		}

		// content has started
		else if (readBytes >= bitmapImage.headerSize) {
			if (readBytes == bitmapImage.headerSize) {
				puts("Content:");
			}

			if (columnCursor == 0) {
				putchar('[');
			}

			printf("%02X", currentByte);

			columnCursor++;

			if (columnCursor == 3) {
				colorsCursor++;
				columnCursor = 0;
				printf("] ");
			}

			if (colorsCursor == COLORS_PER_LINE) {
				colorsCursor = 0;
				putchar('\n');
			}
		}
	}

	fclose(bitmapFile);

	putchar('\n');
	puts("------------------------");
	printf("Header in bytes: %u \n", bitmapImage.headerSize);
	printf("Total in bytes: %u \n", bitmapImage.size);
	putchar('\n');

	return 0;
}
