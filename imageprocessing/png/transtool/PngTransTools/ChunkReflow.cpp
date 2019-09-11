#include "ChunkReflow.h"
#include "base.h"

ChunkReflow::ChunkReflow(void)
{
}

ChunkReflow::~ChunkReflow()
{
	mArrays.clear();
	if (m_pInStream)
		free(m_pInStream);
	
	if (m_pOutStream)
		free(m_pOutStream);
}

boolean ChunkReflow::alloc(unsigned char* const buffer, unsigned int size)
{
	if (!buffer || !size)
		return false;

	m_pInStream = (unsigned char*)malloc(size);

	if (m_pInStream)
		memcpy(m_pInStream, buffer, size);
	else
	{
		printf("Failed Memory Alloc ");
		return false;
	}

	this->m_nInSize = size;

	return true;
}

boolean ChunkReflow::canConvert(char* buffer)
{
	if (!buffer)
		return false;

	png_byte png_header[256] = {0};
	
	memcpy(png_header, (unsigned char*)buffer, 256);
	png_byte cgbi[4];
	memcpy(cgbi, &png_header[12], 4);
	
	if (memcmp((char*) cgbi, "CgBI", 4) == 0)
		return true;
	
	printf("current file was standard png format.");
	return false;
}

unsigned ChunkReflow::updateCrc(unsigned char *source, unsigned char *pdata, unsigned int length)
{
	if (!source) {
		printf("failed crc %s",__FILE__);
		return NULL;
	}

	unsigned int crc = NULL;
	crc		= crc32(0, source, 4);
	return  crc32(crc, pdata, length);
}

boolean ChunkReflow::convert(unsigned char* const buffer, unsigned int size)
{
	if (!buffer)
		return false;

	if (canConvert((char*)buffer) == false)
		return false;
	
	if (alloc(buffer, size) == false)
		return false;
	
	int i = 0;

	png_defalut_chunk* chunk = NULL;
	unsigned char* pStreamOffset = m_pInStream;
	pStreamOffset += 8; // magic number 만큼 offset 이동

	if (split(pStreamOffset) == false) {
		return false;
	}
	
	if (arrange() == false) {
		return false;
	}

	m_pOutStream = (unsigned char*)malloc(sizeof(unsigned char) * CGBI_MAX_BUFSIZE);
	if (!m_pOutStream)
	{
		return false;
	}

	unsigned int pngIndex = NULL;
	memcpy(&m_pOutStream[pngIndex], pngheader, 8);
	pngIndex += 8;

	unsigned int idat_seen = 0;
	chunk = (png_defalut_chunk*)mArrays.data();

	const int size2 = mArrays.size();
	for (i = 0; i< size2; i++) 
	{
		int tmp;
		unsigned int crc;				

		tmp = convertNtoHL(chunk[i].length);
		crc = convertHtoNL(chunk[i].crc);

		if (memcmp(chunk[i].name, cgbichunk, 4))
		{ // Anything but a CgBI
			if (memcmp(chunk[i].name, "IDAT", 4) == 0) 
			{
				idat_seen++;

				if (idat_seen - 1 != 0)
					continue;
			}

			memcpy(&m_pOutStream[pngIndex], &tmp, 4);
			pngIndex +=4;
			memcpy(&m_pOutStream[pngIndex], chunk[i].name, 4);
			pngIndex +=4;

			if (chunk[i].length > 0)
			{
				memcpy(&m_pOutStream[pngIndex], chunk[i].data, chunk[i].length);
				pngIndex += chunk[i].length;
			}

			memcpy(&m_pOutStream[pngIndex], &crc, 4);
			pngIndex+=4;
		}

		if (!memcmp(chunk[i].name, endchunk, 4))
		{
			break;
		}
	}

	m_nOutSize = pngIndex;					
	return true;				
}

boolean ChunkReflow::split(unsigned char* pStreamOffset)
{
	unsigned int i  = NULL;

	png_defalut_chunk chunk = {0,};

	for (i = 0; i<CGBI_MAX_CHUNKS; i++)
	{
		memcpy(&chunk.length, pStreamOffset, 4);
		chunk.length = convertNtoHL(chunk.length);//ntohl(chunk->length);

		pStreamOffset += 4;				
		memcpy(chunk.name, pStreamOffset, 4);

		pStreamOffset += 4;				
		if(chunk.length)
		{
			chunk.data = (unsigned char*)malloc(chunk.length);

			if (!chunk.data)
			{
				return false;
			}

			memcpy(chunk.data, pStreamOffset, chunk.length);
		}
		else
			chunk.data = NULL;

		pStreamOffset += chunk.length;
		memcpy(&chunk.crc, pStreamOffset, 4);
		chunk.crc = convertNtoHL(chunk.crc);//ntohl(chunk->crc);
		pStreamOffset += 4;

		mArrays.push_back(chunk);
		if (!memcmp(chunk.name, endchunk, 4))
		{
			// End of img.
			break;
		}
	}

	free(m_pInStream);
	return true;
}

boolean ChunkReflow::arrange()
{	
	png_defalut_chunk* data = (png_defalut_chunk*)mArrays.data();
	if (!data) {
		return false;
	}

	// Poke at any IDAT chunks and de/recompress them
	const int size = mArrays.size();
	for (int i = 0; i<size; i++) 
	{					
		int ret;
		z_stream infstrm, defstrm;
		unsigned char* inflatedbuf;
		unsigned char* deflatedbuf;

		/* End chunk */
		char* name = (char*)mArrays[i].name;
		if (memcmp(name, cgbichunk, 4) == 0) {
			continue;

		}

		inflatedbuf = (unsigned char*)malloc(CGBI_MAX_BUFSIZE);

		if (!inflatedbuf)
		{
			return false;
		}

		infstrm.zalloc = Z_NULL;
		infstrm.zfree = Z_NULL;
		infstrm.opaque = Z_NULL;
		infstrm.avail_in = mArrays[i].length;
		infstrm.next_in = mArrays[i].data;
		infstrm.next_out = inflatedbuf;
		infstrm.avail_out = CGBI_MAX_BUFSIZE;

		if (inflateInit2(&infstrm,-8) != Z_OK)
		{
			DEBUG_ASSERT(false);
			//die("ZLib error");
			return false;
		}

		ret = inflate(&infstrm, Z_NO_FLUSH);
		switch (ret) {
		case Z_NEED_DICT:
			ret = Z_DATA_ERROR;     /* and fall through */
		case Z_DATA_ERROR:
		case Z_MEM_ERROR:
			printf("ZLib error! %d\n", ret);
			inflateEnd(&infstrm);
		}

		inflateEnd(&infstrm);

		// Now deflate again, the regular, PNG-compatible, way
		deflatedbuf = (unsigned char *)malloc(CGBI_MAX_BUFSIZE);

		if (!deflatedbuf)
		{
			return false;
		}

		defstrm.zalloc = Z_NULL;
		defstrm.zfree = Z_NULL;
		defstrm.opaque = Z_NULL;
		defstrm.avail_in = infstrm.total_out;
		defstrm.next_in = inflatedbuf;
		defstrm.next_out = deflatedbuf;
		defstrm.avail_out = CGBI_MAX_BUFSIZE;

		deflateInit(&defstrm, Z_DEFAULT_COMPRESSION);
		deflate(&defstrm, Z_FINISH);

		free(mArrays[i].data);

		if (deflatedbuf)
		{
			mArrays[i].data = (unsigned char*)malloc(defstrm.total_out);	
			if (mArrays[i].data)
				memcpy(mArrays[i].data, deflatedbuf, defstrm.total_out);
			else
				return false;
		}

		mArrays[i].length = defstrm.total_out;
		mArrays[i].crc = updateCrc(mArrays[i].name, mArrays[i].data, mArrays[i].length);
		deflateEnd (&defstrm);

		if (memcmp(mArrays[i].name, datachunk, 4) == 0)
			m_idat_chunk++;

		free(inflatedbuf);
		free(deflatedbuf);

		printf("Chunk: %c%c%c%c, new length: %d, new CRC: %08x\n",
			mArrays[i].name[0], mArrays[i].name[1],
			mArrays[i].name[2], mArrays[i].name[3],
			mArrays[i].length, mArrays[i].crc);
	}

	if (m_idat_chunk >= 1)
		return true;
	else
		return false;
}

void ChunkReflow::save(char* path) {

	if (!path) {
		printf("Failed Write Data");
		return;
	}
	// verify system authority
	const int size = mArrays.size();
	for(int i =0; i <size; i++) {
		png_defalut_chunk chunk = mArrays[i];
		printf("[%04d][%s][%04d]\n", chunk.length, chunk.name, chunk.crc);
	}

	return;
}