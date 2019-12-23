#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	
	std::ios::sync_with_stdio(false); cin.tie(0);

	int n; cin >> n;

	vector<double > arr(n);
	for(int i=0; i<n; i++)
		cin >> arr[i];

	double sol = -1;

	for(int i=0; i<n; i++) {
		double cand = 1;
		for(int j=i; j<n; j++) {
			cand = cand * arr[j];

			if(cand > sol) {
				sol = cand;
			}
		}
	}

    // 항상 잊지 말것 자리수 출력
    cout.setf(ios::fixed);
    cout.precision(3);
    cout << sol << "\n";
	return 0;
}