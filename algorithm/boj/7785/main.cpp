#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>         // greater 사용 위해 필요  
#include <string>
#include <map>
#include <math.h>
#include <stack>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); cin.tie(0);

	int n; cin >> n;

	map<string, string> m;
	while(n--) {
		string s; cin >> s;
		string ss; cin >> ss;
		m[s] = ss;
	}

	map<string, string>::reverse_iterator iter;
	for(iter = m.rbegin(); iter != m.rend(); iter++) {

		if (iter->second == "enter") {
			cout << iter->first << "\n";
		}
	}
	return 0;
}