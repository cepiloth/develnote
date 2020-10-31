#pragma once _fileraii_

#include <string>
using namespace std;

/*
* RAII 이 적용된 class
*/
class FileRAII {
public:
	FileRAII(const string& path, const string& mode) {
		this->file = std::fopen(path.c_str(), mode.c_str());
	}

	// 소멸자에서 instance 를 해제하게함
	~FileRAII() {
		std::fclose(file);
	}

	std::FILE* file;
};

/* USAGE :
int main(int argc, char** argv)
{
	// stack 에 할당
	FileRAII file("test.txt", "wb+");

	void* buff = std::malloc(4);
	if (buff == nullptr) {
		return -1;
	}

	return 0;
}
*/