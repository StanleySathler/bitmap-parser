#ifndef __BITMAP_H__
#define __BITMAP_H__

	/**
	 * @brief Constant terms used by Microsoft's Bitmap documentation.
	 */
	#define WORD 2
	#define DWORD 4
	#define LONG 4

	/**
	 * @brief Represent a Bitmap image structure.
	 */
	typedef struct {
		unsigned int bfSize;
		unsigned int bfOffBits;
		unsigned int biSize;
		unsigned int biWidth;
		unsigned int biHeight;
		unsigned int biBitCount;
		unsigned int biSizeImage;
		unsigned char* content;
	} BitmapImage;

	/**
	 * @brief Read next N bytes from the given image.
	 */
	int
	read_next_bytes(FILE *file, unsigned int bytes);

	/**
	 * @brief Parse the given image into a BitmapImage struct.
	 */
	void
	bmp_parse_file(BitmapImage *pImage, FILE *file);

#endif /* __BITMAP_H__ */
