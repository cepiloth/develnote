#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>         // greater 사용 위해 필요  
#include <string>
#include <map>
#include <math.h>
using namespace std;


long long fac(long n) {
	if (n == 1 || n == 0) {
		return 1;
	}

	return n * fac(n-1);
}

int main() {

	int a, b, v;
	cin >> a >> b >> v;
    // v-a 달팽이가 최상위에 올라가있는 지점 이며 마지막 dist 가 된다.
    // a-b 달팽이가 하루 동안에 올라갈 수 있는 거리가 된다.
    // v-a / a-b 는 최상위로 올라가는 거리의 일 수를 구한다.
	cout << (int)ceil((double)(v-a) / (double)(a-b) + 1 ) << "\n";
	return 0;
}