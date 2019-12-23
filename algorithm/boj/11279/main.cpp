#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
using namespace std;

int main() {
	
	std::ios::sync_with_stdio(false); cin.tie(0);

	priority_queue<int, vector<int>, less<int>> q;

	int n; cin >> n;

	while(n--) {
		int cand; cin >> cand;
		
		if (cand == 0) {
			if (q.empty()) {
				cout << 0 << "\n";
			} else {
				cout << q.top() << "\n";
				q.pop();
			}
		} else {
			q.push(cand);
		}		
	}
	return 0;
}