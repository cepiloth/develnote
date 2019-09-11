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
	//1. ���� �������� ����
	sort(num.begin(), num.end());
  
	//2. ������ �ִ� ������� ã�´�.
	long long firstValue = gcd(num[0], num[1]);
	//3. ������ �ִ� ������� ã�´�.
	long long value = num[0] * num[1] / firstValue;
	//cout << "�ּҰ���� " << value << endl;
  
	int size = num.size();
	//4. ���� ã�� �ִ� ����� ������ [2][3]�� �ݺ� �Ѵ�.
	for(int i=2; i<size; i++) {
    	long long value2 = gcd(value, num[i]);
    	firstValue = value * num[i] / value2;
    	value = firstValue;
	}
  
	return value;
}
