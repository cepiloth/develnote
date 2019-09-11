# PngTransTools1.0
PngTransTools is an open source project that uses libpng and zlib.

# Motivation

libpng with CgBI support.

- what is CgBI Chunk?
The CgBI file format, thus named for its extra header, is Apple's proprietary extension to the PNG[1] image format.

- Diffrences from PNG.
 These modifications cause the generated images to be invalid as per the current version of the PNG standard.
 extra critical chunk (CgBI)
 byteswapped (RGBA -> BGRA) pixel data, presumably for high-speed direct blitting to the framebuffer
 zlib header, footer, and CRC removed from the IDAT chunk
 premultiplied alpha (color' = color * alpha / 255)

 To account for or apply these modifications, libpng needs to be patched to accept the "invalid" zlib compression window (a 15-bit window is the default, supplying -15 to zlib will cause it to omit headers/footers/CRC info).

- CgBI Chunk
CgBI is a four-byte critical chunk added to the beginning of all "optimized" PNG files.

- Known Contents
 0x50 0x00 0x20 0x06
 0x50 0x00 0x20 0x02 (seen if input image was already RGBA)
 At least the lower parts of the content correspond to the documented CGBitmapInfo bitmask.

# History
- 2017-10-19 Update to the lastest version(lpng1632)
- 2017-10-19 Support to visual studio 2012.

# ZipRepairTools
ZipRepairTools is an open source project that uses pkzip archive and zlib.

# Feature
The zip archive was consisted of three file header(local, central, end).
and each header has a signature.

all multi-byte values in the header are stored in little-endian byte order.
all length fields count the length in bytes.

- Local file header signature = 0x04034b50 (read as a little-endian number)
- Central directory file header signature = 0x02014b50
- End of central directory signature = 0x06054b50

# License
BSD. Free for personal and commercial use.
