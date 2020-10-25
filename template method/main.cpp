#include "max1.hpp"
#include <iostream>
#include <string>

template<typename T>
void foo(T t)
{
	undeclared();			// undeclared()가 알려지 않았다면 첫 번째 단계 컴파일 오류
	undeclared(T);			// undeclared(T)가 알려지지 않았다면 두 번째 단계 컴파일 오류
	static_assert(sizeof(int) > 10, "int too small");	//sizeof(int)<=10 라면 항상 실패
	static_assert(sizeof(T) > 10, "int too small");		// 크기가 10보다 작거나 같은 T로 인스턴스화 됐다면 실패
}

int main() {

	int i = 42;
	std::cout << "max(7, i):" << ::max(7, i) << '\n';

	double f1 = 3.4;
	double f2 = -6.7;
	std::cout << "max(f1, f2):" << ::max(f1, f2) << '\n';

/*
﻿ max() 템플릿을 호출할 때마다 ::으로 한정했다는 것을 눈여겨보자. 이렇게 표시하면 전역 네임스페이스에 우리의 max() 템플릿을 찾는다. 
표준 라이브러리에도 std::max() 템플릿이 있기 때문에 ::로 한정하지 않으면 (오버 로딩 해석 & C++의 룩업법칙) 에서 모호하게 될 수도 있다.﻿
*/
	return 0;
}