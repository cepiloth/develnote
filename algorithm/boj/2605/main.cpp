#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

int main() {
	
	std::ios::sync_with_stdio(false); cin.tie(0);

	int n; cin >> n;

	list<int> arr;
	list<int>::iterator iter;
	for(int i=1; i<=n; i++) {
		int cand; cin >> cand;

		for(iter = arr.begin(); iter != arr.end(); iter++) {
			if (cand == 0) {
				break;
			}
			cand--;
		}

		arr.insert(iter, i);
	}
	
	
	for(auto i= arr.rbegin(); i != arr.rend(); i++) {
		cout << *i << " ";
	}
	return 0;
}