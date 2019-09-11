#pragma once

#include <vector>
#include <algorithm>
using namespace std;

#include "libpng/png.h"
#include "libpng/pngpriv.h"

#include "base.h"

class ChunkReflow
{
public:
	ChunkReflow(void);
	~ChunkReflow(void);

	boolean canConvert(char* buffer);
	boolean convert(unsigned char* const buffer, unsigned int size);
	void save(char* path);

protected:
	unsigned int updateCrc(unsigned char *source, unsigned char *pdata, unsigned int length);
	boolean alloc(unsigned char* const buffer, unsigned int size);
	boolean split(unsigned char* pStream);
	boolean arrange();

private:
	unsigned int	m_nInSize;
	unsigned int	m_nOutSize;

	unsigned char   m_idat_chunk;

	unsigned char*	m_pOutStream;
	unsigned char*	m_pInStream;

	vector<png_defalut_chunk> mArrays;
};
