#pragma once

class ChunkUtils
{
public:
	ChunkUtils(CString path);
	~ChunkUtils(void);

	void display();
private:
	CString path;
};

