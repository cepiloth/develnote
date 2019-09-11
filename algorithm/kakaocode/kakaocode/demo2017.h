#ifndef __KAKAO_DEMO_2017_H__
#define __KAKAO_DEMO_2017_H__

#include<iostream>
#include<string>
#include<vector>
using namespace std;

/************************************************************************/
/* ���� 1 �� �ڸ��� �ձ��ϱ� */
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
/* ���� 2 ���� Ȯ�� */
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
/* ����3 ���簢�� ����� */
/************************************************************************/
bool vector<int> demo_solution3(vector<vector<int> > v) {
	//vector<vector<int> >�� ���� ������ ���� �о�� �� �ֽ��ϴ�.
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
	int hi = 1001;	// ���� �ȵǴ°� ��Ÿ��
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
/* ����4 ���� ū ���簢�� ã�� */
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
/* ������                                                              */
/************************************************************************/
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

int demo_solution5(vector<vector<int>> land)
{
	// dp -1 �� �ʱ�ȭ 
	memset(dp, -1 ,sizeof(dp));
	kSize = land.size();

	// �������� ����Ҽ� �ֵ��� ���� ���� ��
	for(int n=0;n<kSize;n++){
		for(int m=0;m<4;m++)
			field[n][m] = land[n][m];
	}

	int ans = 0;
	// ������ ������ 4�� ������ 
	for(int n=0;n<4;n++){
		ans = max(ans, solve(0, n));
	}
	return ans;
}


#endif //__KAKAO_LEVEL4_H__