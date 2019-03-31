## Bitmap Parser

This program is a very simple Bitmap parser. It reads byte by byte from the image file and builds a small struct element containing some information about the image.

The goal here is to understand how an image file works under the hood. The Bitmap format was chosen because it often does not contain compression. It makes Bitmap an easier start point.

This program can easily fail in any other platform rather than the Ubuntu 18.04 Bionic Beaver. Also, it can easily fail with any other image rather than the original one. It happens because the knowledge so far, on both Bitmap parsing and C programming, are very limited.
