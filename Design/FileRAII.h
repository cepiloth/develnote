#pragma once _fileraii_

#include <string>
using namespace std;

/*
* RAII �� ����� class
*/
class FileRAII {
public:
	FileRAII(const string& path, const string& mode) {
		this->file = std::fopen(path.c_str(), mode.c_str());
	}

	// �Ҹ��ڿ��� instance �� �����ϰ���
	~FileRAII() {
		std::fclose(file);
	}

	std::FILE* file;
};

/* USAGE :
int main(int argc, char** argv)
{
	// stack �� �Ҵ�
	FileRAII file("test.txt", "wb+");

	void* buff = std::malloc(4);
	if (buff == nullptr) {
		return -1;
	}

	return 0;
}
*/