#include <stdio.h>

#include "ChunkReflow.h"

#include <vld.h>

int main2()
{
	FILE* fp = fopen("test.png","rb");
	if (!fp)
	{
		fclose(fp);
		printf("Failed Load data \r\n");
	}

	fseek(fp, 0, SEEK_END);
	int file_length = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	char* pData = (char*)malloc(file_length);
	memset(pData, 0, file_length);
	fread(pData, file_length, 1, fp);
	fflush(fp);
	fclose(fp);

	unsigned int result_length = 0;
	unsigned char* pResult = 0;

	ChunkReflow reflow;

	if (reflow.convert((unsigned char*)pData, file_length) == false)
		return false;

	reflow.save("test_reulst.png");

	return 0;
}