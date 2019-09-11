#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <math.h>
#include <memory.h>
using namespace std;

#define MAX_SIZE 100
#define INF 0x7fffffff
#define CENDL "\n"
#define ll long long

#define c_reverse(s) reverse(s.begin(), s.end())
#define c_sort(s) sort(s.begin(), s.end())
#define print_vector(v) for(int i=0; i<v.size(); i++) cout << v[i];

int table[101][101] = { 0, };
int main() {

	cin.tie(0);
	std::ios::sync_with_stdio(false);

	string s, s2; cin >> s >> s2;

	const int size = s.size();
	const int size2 = s2.size();

	int sol = 0;

	for (int i = 0; i < size; i++) {

		int cand = i + size2;
		if (cand > size) {
			break;
		}

		bool ok = true;
		for (int x = 0, j = 0; j < size2; j++, x++) {
			
			if (s[x] != s2[j]) {
				ok = false;
			}
		}

		if (ok) {
			sol++;
			i += size2;
		}
	}

	cout << sol << CENDL;
	return 0;
}