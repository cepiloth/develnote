#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); cin.tie(0);

	int x; cin >> x;

	int i=0;
	for (i = 1; x > 0; i++) {
		x = x - i;
	}

	if (i%2 == 1) {
		cout << i + x-1 << "/" << 1 - x << endl;
	} else if (i % 2 == 0) {
		cout << 1-x << "/" << i+x-1 << endl;
	}

	return 0;
}