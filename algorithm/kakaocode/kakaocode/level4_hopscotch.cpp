#include "level4.h"

// [LEVEL4] �����Ա� ����

int kSize;
int field[100001][4];
int dp[100001][4];

int solve(int y, int x) {

	// ������ ���� ������ ����
	if (y == kSize) 
		return 0;

	// ���� �湮�� ��ġ ��Ͽ�
	int &ret = dp[y][x];
	if (ret != -1)  {
		return ret;
	}

	ret = 0;

	// n�� ���� ������ �̵��ϸ鼭 ���� ���Ҹ� ã�´�.
	// x �� ���� ��ġ�� ����
	for (int n = 0;n < 4;n++) {
		// ���� ��ġ��� pass �ϰ� ���� ��ġ�� ���Ѵ�.
		if (x == n) 
			continue;
		// �Ʒ�ĭ���� �̵��ϸ� ���� ���� �ջ�
		ret = max(ret, solve(y + 1, n) + field[y][n]);
	}

	return ret;
}

int hopscotch(vector<vector<int> > l){

	// dp -1 �� �ʱ�ȭ 
	memset(dp, -1 ,sizeof(dp));
	kSize = l.size();

	// �������� ����Ҽ� �ֵ��� ���� ���� ��
	for(int n=0;n<kSize;n++){
		for(int m=0;m<4;m++)
			field[n][m] = l[n][m];
	}

	int ans = 0;
	// ������ ������ 4�� ������ 
	for(int n=0;n<4;n++){
		ans = max(ans, solve(0, n));
	}
	return ans;
}