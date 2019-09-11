#ifndef __KAKAO_DEMO_2017_H__
#define __KAKAO_DEMO_2017_H__

#include<iostream>
#include<string>
#include<vector>
using namespace std;

/************************************************************************/
/* 데모 1 각 자릿수 합구하기 */
/************************************************************************/
int demo_soultion1(int n) {
	int result = 0;
	while (n)
	{
		result += n%10;
		n = n/10;
	}
	return result;
}


/************************************************************************/
/* 데모 2 순열 확인 */
/************************************************************************/
bool demo_solution2(vector<int> arr)
{
	bool answer = true;
	sort(arr.begin(), arr.end());

	int size = arr.size();
	for(int i=0; i<size; i++) {
		if(arr[i] != i+1) {
			answer = false;
			break;
		}
	}
	return answer;
}

/************************************************************************/
/* 데모3 직사각형 만들기 */
/************************************************************************/
bool vector<int> demo_solution3(vector<vector<int> > v) {
	//vector<vector<int> >의 값은 다음과 같이 읽어올 수 있습니다.
	int x1 = v[0][0];
	int x2 = v[1][0];
	int x3 = v[2][0];
	int x4 = 0;

	int y1 = v[0][1];
	int y2 = v[1][1];
	int y3 = v[2][1];
	int y4 = 0;

	if(x1 == x2) {
		x4 = x3;
	} else if (x1 == x3){
		x4 = x2;
	} else {
		x4 = x1;
	}

	if(y1 == y2) {
		y4 = y3;
	} else if (y1 == y3){
		y4 = y2;
	} else {
		y4 = y1;
	}

	vector<int> ans;
	ans.push_back(x4);
	ans.push_back(y4);
	return ans;
}


int calcMX(const vector<vector<int>>& psum, int endY, int endX) {
	int hi = 1001;	// 답이 안되는걸 나타냄
	int lo = 0;
	int mid = 0;

	while (lo + 1 < hi)
	{
		mid = (lo+hi)/2;
		bool ok = true;
		int beginY = endY - mid + 1;
		int beginX = endX - mid + 1;
		if (beginY < 0 || beginX < 0)
			ok = false;

		int sum = 0;
		if (ok)
			sum = psum[endY][endX] - (beginY == 0 ? 0 : psum[beginY-1][endX]) -(beginX == 0 ? 0 : psum[endY][beginX - 1])
			+ ((beginX == 0 || beginY == 0) ? 0 : psum[beginY - 1][beginX - 1]);
		if (sum != mid * mid)
			ok = false;

		if (ok == true)
			lo = mid;
		else 
			hi = mid;
	}
	return lo;
}

/************************************************************************/
/* 데모4 가장 큰 정사각형 찾기 */
/************************************************************************/
int demo_solution4(vector<vector<int>> board)
{
	int answer = 1234;
	int size = board.size();
	vector<vector<int>> psum = board;
	psum[0][0] = board[0][0];
	for (int i = 1; i < board[0].size(); ++i)
		psum[0][i] = psum[0][i - 1] + board[0][i];
	for (int i = 1; i < board.size(); ++i)
		psum[i][0] = psum[i - 1][0] + board[i][0];

	for (int i = 1; i < board.size(); ++i)
		for (int j = 1; j < board[0].size(); ++j)
			psum[i][j] = psum[i-1][j] + psum[i][j-1] + board[i][j] - psum[i-1][j-1];

	int sol = 0;
	for (int i = 0; i < psum.size(); ++i)
		for (int j = 0; j < psum[0].size(); ++j) {
			sol = max(sol, calcMX(psum, i, j));	// logN
		}
		return sol * sol;
}

/************************************************************************/
/* 데모문제                                                              */
/************************************************************************/
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

int demo_solution5(vector<vector<int>> land)
{
	// dp -1 로 초기화 
	memset(dp, -1 ,sizeof(dp));
	kSize = land.size();

	// 전역에서 사용할수 있도록 값을 복사 함
	for(int n=0;n<kSize;n++){
		for(int m=0;m<4;m++)
			field[n][m] = land[n][m];
	}

	int ans = 0;
	// 문제의 조건이 4열 임으로 
	for(int n=0;n<4;n++){
		ans = max(ans, solve(0, n));
	}
	return ans;
}


#endif //__KAKAO_LEVEL4_H__