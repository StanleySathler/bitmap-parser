#include <stdio.h>
#include <stdlib.h>

#define COLORS_PER_LINE 3
#define WORD 2
#define DWORD 4
#define LONG 4
#define ERROR_MISSING_FILENAME 15


typedef struct {
	unsigned int bfSize;
	unsigned int bfOffBits;
	unsigned int biSize;
	unsigned int biWidth;
	unsigned int biHeight;
	unsigned int biBitCount;
	unsigned int biSizeImage;
	char* content;
} BitmapImage;


void printContent(BitmapImage *pImage);
void printDetails(BitmapImage *pImage);
void parse(BitmapImage *pImage, FILE *file);
int readBytes(FILE *file, unsigned int bytes);


int main(int argc, char **argv)
{
	FILE *bitmapFile;
	BitmapImage bitmapImage;

	if (argv[1] == 0) {
		printf("You must provide a file name: %s <filename> \n", argv[0]);
		exit(ERROR_MISSING_FILENAME);
	}

	bitmapFile = fopen(argv[1], "rb");
	parse(&bitmapImage, bitmapFile);
	fclose(bitmapFile);

	printDetails(&bitmapImage);
	return 0;
}


void printDetails(BitmapImage *pImage)
{
	putchar('\n');
	puts("Content:");
	printContent(pImage);
	putchar('\n');
	puts("--------------------------------------");
	printf("File size: ....................... %uB \n", pImage->bfSize);
	printf("Header length: ................... %uB \n", pImage->bfOffBits);
	printf("Width: ........................... %upx \n", pImage->biWidth);
	printf("Height: .......................... %upx \n", pImage->biHeight);
	printf("Color depth: ..................... %ub \n", pImage->biBitCount);
	printf("Content length: .................. %uB \n", pImage->biSizeImage);
	puts("--------------------------------------");
}


void printContent(BitmapImage *pImage)
{
	for (unsigned int i = 0; i < pImage->biSizeImage; i++) {
		printf("%d ", pImage->content[i]);

		if ((i % pImage->biWidth) == 0)
			putchar('\n');
	}
}


void parse(BitmapImage *pImage, FILE *file)
{
	int currentByte;
	long int cursor;

	while ((currentByte = fgetc(file)) != EOF) {
		cursor = ftell(file);

		if (cursor == 3)
			pImage->bfSize = currentByte + readBytes(file, (DWORD - 1));

		else if (cursor == 11)
			pImage->bfOffBits = currentByte + readBytes(file, (DWORD - 1));

		else if (cursor == 15)
			pImage->biSize = currentByte + readBytes(file, (DWORD - 1));

		else if (cursor == 19)
			pImage->biWidth = currentByte + readBytes(file, (LONG - 1));

		else if (cursor == 23)
			pImage->biHeight = currentByte + readBytes(file, (LONG - 1));

		else if (cursor == 29)
			pImage->biBitCount = currentByte + readBytes(file, (WORD - 1));

		else if (cursor == 35)
			pImage->biSizeImage = currentByte + readBytes(file, (DWORD - 1));

		// content
		else if (cursor == (pImage->bfOffBits + 1)) {
			pImage->content = (char*) malloc(pImage->biSizeImage);
			pImage->content[0] = currentByte;

			for (unsigned int i = 1; i < pImage->biSizeImage; i++) {
				int byte = fgetc(file);
				pImage->content[i] = byte;
			}
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
