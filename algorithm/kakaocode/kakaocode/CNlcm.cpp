#include "CNlcm.h"

CNlcm::CNlcm(){

};
	
long long CNlcm::execute(vector<int> num) {
	return nlcm(num);
}

long long CNlcm::gcd(long long a, long long b){
	return b ? gcd(b, a%b) : a;
}

long long CNlcm::nlcm(vector<int> num){
	long long answer = 0;
	//1. 오름 차순으로 정렬
	sort(num.begin(), num.end());
  
	//2. 최초의 최대 공약수를 찾는다.
	long long firstValue = gcd(num[0], num[1]);
	//3. 최초의 최대 공배수를 찾는다.
	long long value = num[0] * num[1] / firstValue;
	//cout << "최소공배수 " << value << endl;
  
	int size = num.size();
	//4. 최초 찾은 최대 공배수 값으로 [2][3]을 반복 한다.
	for(int i=2; i<size; i++) {
    	long long value2 = gcd(value, num[i]);
    	firstValue = value * num[i] / value2;
    	value = firstValue;
	}
  
	return value;
}
