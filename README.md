## Bitmap Parser

This program is a very simple Bitmap parser. It reads byte by byte from the image file and builds a small struct element containing some information about the image.

The goal here is to understand how an image file works under the hood. The Bitmap format was chosen because it often does not contain compression. It makes Bitmap an easier start point.

This program can easily fail in any other platform rather than the Ubuntu 18.04 Bionic Beaver. Also, it can easily fail with any other image rather than the original one. It happens because the knowledge so far, on both Bitmap parsing and C programming, are very limited.

## Checklist

**Footer**
- [x] Print total file size
- [x] Print total header length
- [x] Print image width (in pixels)
- [x] Print image height (in pixels)
- [x] Print color depth
- [x] Print total content length

**Content**
- [x] Print color of each pixel (grouped by `()`)
- [x] Print bytes in the right order (considering _little-endian_)
- [x] Remove new line bytes from printed output
- [ ] Print colors in the right order (considering _top-down / bottom-up_)
