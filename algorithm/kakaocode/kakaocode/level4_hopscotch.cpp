#include "level4.h"

// [LEVEL4] 땅따먹기 게임

int kSize;
int field[100001][4];
int dp[100001][4];

int solve(int y, int x) {

	// 마지막 까지 왔으면 종료
	if (y == kSize) 
		return 0;

	// 이전 방문한 위치 기록용
	int &ret = dp[y][x];
	if (ret != -1)  {
		return ret;
	}

	ret = 0;

	// n을 오른 쪽으로 이동하면서 가장 원소르 찾는다.
	// x 는 이전 위치를 뜻함
	for (int n = 0;n < 4;n++) {
		// 이전 위치라면 pass 하고 다음 위치를 정한다.
		if (x == n) 
			continue;
		// 아래칸으로 이동하며 현재 값을 합산
		ret = max(ret, solve(y + 1, n) + field[y][n]);
	}

	return ret;
}

int hopscotch(vector<vector<int> > l){

	// dp -1 로 초기화 
	memset(dp, -1 ,sizeof(dp));
	kSize = l.size();

	// 전역에서 사용할수 있도록 값을 복사 함
	for(int n=0;n<kSize;n++){
		for(int m=0;m<4;m++)
			field[n][m] = l[n][m];
	}

	int ans = 0;
	// 문제의 조건이 4열 임으로 
	for(int n=0;n<4;n++){
		ans = max(ans, solve(0, n));
	}
	return ans;
}