#include "max1.hpp"
#include <iostream>
#include <string>

int main() {

	int i = 42;
	std::cout << "max(7, i):" << ::max(7, i) << '\n';

	double f1 = 3.4;
	double f2 = -6.7;
	std::cout << "max(f1, f2):" << ::max(f1, f2) << '\n';

/*
max() 템플릿을 호출할 때마다 ::으로 한정했다는 것을 눈여겨보자. 이렇게 표시하면 전역 네임스페이스에 우리의 max() 템플릿을 찾는다.
퓨준 라이브러리에도 std::max() 템플릿이 있기 때문에 ::로 한정하지 않으면 (오버로딩 해석 & C++의 룩업법칙) 에서  모호하게 될 수도 있다.
*/
	return 0;
}