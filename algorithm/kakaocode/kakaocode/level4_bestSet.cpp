#include "level4.h"



vector<int> returnError() {
	vector<int> warning;
	warning.push_back(-1);
	return warning;
}

// [LEVEL4] �ְ��� ����
vector<int> bestSet(int no,int sum)
{
	const int findMAX = no;
	vector<int> answer;

	// 1. ���� �Һ���? ������ ���� ������ �պ��� ũ�ٸ� ����
	if(no > sum) {
		return returnError();
	}

	// 2. ù ��° ������ ���Ҹ� ã�´�.
	int cond = sum / no;
	answer.push_back(cond);
	sum = sum - cond;

	// 3. �ϳ��� ���Ҹ� ã������ ���� ���Ҹ� ���� �Ѵ�.
	no--;

	// 4. �ӽ� ������ �����Ͽ� �ݺ��� ���� Ű ������ �����.
	int key = no;

	// 5. �ʱ⹮�� ã�ƾ��� [���� - 1], ���ǹ��� ã�ƾ� �� ���ҷ� ����
	for(int i=findMAX-no; i< findMAX; i++) {
		// 6. �ݺ��� �������� [2]�� ������ �ݺ��Ѵ�.
		cond = sum / key;
		answer.push_back(cond);
		sum -= cond;
		key--;
	}

	return answer;
}