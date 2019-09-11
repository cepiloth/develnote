#include "level4.h"



vector<int> returnError() {
	vector<int> warning;
	warning.push_back(-1);
	return warning;
}

// [LEVEL4] 최고의 집합
vector<int> bestSet(int no,int sum)
{
	const int findMAX = no;
	vector<int> answer;

	// 1. 집합 불변식? 집합의 값이 원소의 합보다 크다면 에러
	if(no > sum) {
		return returnError();
	}

	// 2. 첫 번째 집합의 원소를 찾는다.
	int cond = sum / no;
	answer.push_back(cond);
	sum = sum - cond;

	// 3. 하나의 원소를 찾았으니 구할 원소를 감소 한다.
	no--;

	// 4. 임시 변수를 생성하여 반복문 내의 키 변수로 만든다.
	int key = no;

	// 5. 초기문은 찾아야할 [원소 - 1], 조건문은 찾아야 할 원소로 설정
	for(int i=findMAX-no; i< findMAX; i++) {
		// 6. 반복문 내에서는 [2]의 동작을 반복한다.
		cond = sum / key;
		answer.push_back(cond);
		sum -= cond;
		key--;
	}

	return answer;
}