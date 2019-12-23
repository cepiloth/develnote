#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

int table[5][5];
void solve(int d) {
	for(int i=0; i<5; i++) {
		for(int j=0; j<5; j++)
			if (d == table[i][j]) {
				table[i][j] = 0;
				break;
			}
	}
}

bool verify() {
	// row
	int count = 0;
	for(int i=0; i<5;i++){
		int sum = 0;

		for(int j=0; j<5; j++) {	
			sum += table[i][j];
		}
		
		if (sum == 0) {
			count++;
		}
	}

	for(int i=0; i<5;i++){
		int sum = 0;
		
		for(int j=0; j<5; j++) {
			sum += table[j][i];
		}

		if (sum == 0) {
			count++;
		}
	}

	int cand = 0;
	// 대각 방향 검사 [0][0] ~ [4][4]
	for(int i=0; i<5;i++) {
		cand += table[i][i];
	}

	if (cand == 0) {
		count++;
	}

	cand = 0;
	// 대각 방향 검사 [0][4] ~ [4][0]
	for(int i=0; i<5;i++) {
		cand += table[0+i][5-1-i];
	}

	if (cand == 0) {
		count++;
	}

	// 문제 끝까지 읽을 것 교차되는 영역이 3개 이상일 때만 bingo
	if (count >= 3) {
		return true;
	}
	return false;
}

int main() {
	
	std::ios::sync_with_stdio(false); cin.tie(0);


	for(int i=0; i<5; i++) {
		for(int j=0; j<5; j++)
			cin >> table[i][j];
	}

	int sol = 0;
	for(int i=0; i<25; i++) {
		int cand; cin >> cand;
		solve(cand);
		if(verify()) {
			cout << i+1 << "\n";
			break;
		}
	}
	return 0;
}