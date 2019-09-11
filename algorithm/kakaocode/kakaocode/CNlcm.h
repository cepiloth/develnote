#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class CNlcm {
public:
	CNlcm();
	
	long long execute(vector<int> num);

private:
	long long gcd(long long a, long long b);
	long long nlcm(vector<int> num);
};

