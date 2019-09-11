#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>         // greater 사용 위해 필요  
#include <string>
#include <map>
#include <math.h>
using namespace std;

int main() {

	
	string a; cin >> a;
	char ch; cin >> ch;
	string b; cin >> b;

	if (ch == '*') {
		int size = a.size()-1 + b.size()-1;
		cout << 1;
		for(int i =0; i<size; i++) {
			cout << 0;
		}

	} else {

		int lLen = a.size();
		int nLen = b.size();

		if (lLen == nLen) {
			cout << 2;
			for(int i =0; i<lLen-1; i++) {
				cout << 0;
			}
		}
		else {
			int size = max(a.size(), b.size());
			string s;
			reverse(a.begin(), a.end());
			reverse(b.begin(), b.end());

			for(int i =0; i<size; i++) {

				char cand = 0;

				if (i < lLen && a[i]) {
					char sz = a[i] - '0';
					if (cand < sz) {
						cand = 1;
					}
				}

				if (i < nLen && b[i]) {
					char sz = b[i] - '0';
					if (cand < sz) {
						cand = 1;
					}
				}

				cand = cand +'0';
				s.push_back(cand);
			}

			reverse(s.begin(), s.end());
			cout << s;
		}

	}
	return 0;
}