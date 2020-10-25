#include <string>
using namespace std;

//template<typename T>
//void f(T = "") {
//
//}


﻿//위 코드를 쓰고 싶다면 템플릿 파라미터에 대한 기본 인자를 선언해야 한다.
template<typename T = std::string>
void f(T = "") {

}

int main() {

	f(1);	// T 를 int로 연역한다. 따라서 f<int>(1)을 호출한다.
	f();		// 오류: T를 연혁할 수 없다.
}