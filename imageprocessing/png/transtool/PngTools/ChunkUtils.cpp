#include "stdafx.h"
#include "ChunkUtils.h"


ChunkUtils::ChunkUtils(CString path)
{
	this->path = path;
}

void ChunkUtils::display() {

	TRACE("%s", path);
}

ChunkUtils::~ChunkUtils(void)
{
}
