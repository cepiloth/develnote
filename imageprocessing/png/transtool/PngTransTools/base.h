#ifndef __BASE_H__
#define __BASE_H__

inline unsigned int convertNtoHL(unsigned int value)
{
	return ((unsigned int)(value >> 24) & 0x000000FF ) | ((unsigned int)(value >> 8) & 0x0000FF00 ) | ((unsigned int)(value << 8) & 0x00FF0000 ) | ((unsigned int)(value << 24) & 0xFF000000);
}

inline unsigned int convertHtoNL(unsigned int value)
{
	return ((((unsigned int)(value) & 0xff000000) >> 24) | (((unsigned int)(value) & 0x00ff0000) >> 8) | (((unsigned int)(value) & 0x0000ff00) << 8) | (((unsigned int)(value) & 0x000000ff) << 24));
}

typedef struct png_defalut_chunk_s {
	unsigned int	length;
	unsigned char	name[4];
	unsigned char*	data;
	unsigned int	crc;
} png_defalut_chunk;

#define CGBI_MAX_CHUNKS  0x14
#define CGBI_MAX_BUFSIZE 1048576 

#define DEBUG_ASSERT 0

const unsigned char pngheader[8] = {137, 80, 78, 71, 13, 10, 26, 10};
const unsigned char datachunk[4] = {0x49, 0x44, 0x41, 0x54}; // IDAT
const unsigned char endchunk[4] = {0x49, 0x45, 0x4e, 0x44}; // IEND
const unsigned char cgbichunk[4] = {0x43, 0x67, 0x42, 0x49}; // CgBI
const unsigned char ihdrchunk[4] = {0x49, 0x48, 0x44, 0x52}; // IHDR

#endif __BASE_H__