#pragma once

#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 110000)
#	define DWORD_ALIGN  __align(4)
#	define QWORD_ALIGN  __align(8)
#elif defined(_MSC_VER) && (_MSC_VER >= 1300)
#	define DWORD_ALIGN  __declspec(align(4))
#	define QWORD_ALIGN  __declspec(align(8))
#else
#	define DWORD_ALIGN
#	define QWORD_ALIGN
#endif

typedef DWORD_ALIGN struct tagPoChunk {
	unsigned int	length;
	unsigned char	name[4];
	unsigned char*	data;
	unsigned long	crc;
} PoChunk;

#define READ_PNG_CRCCOMPL(c) ((c)^0xffffffff)
#define READ_PNG_CRCINIT (READ_PNG_CRCCOMPL(0))

class ChunkBreaker
{
public:

	static bool check(char* buffer, unsigned long size);

	static unsigned long calc_crc(unsigned long crc, unsigned char *buf, int len);

private:
	static const unsigned long g_crc_table[256]; 
};

