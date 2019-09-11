#include "prime.h"

CPrime::CPrime(){
}
	
int CPrime::execute(int n){
	return numOfPrime(n);
}

int CPrime::numOfPrime(int n){

	// basis 1 n == 2
	if(n == 2) {
		return 1;
	}
  
	for(int i=2;i<n;i++) {
		if(n % i == 0) {
			// �Ҽ��� �ƴ϶�� 0 ��ȯ
			return 0 + numOfPrime(n-1);
			break;
		}
	}
  
  // �Ҽ���� 1�� �����ϰ� ��� �Ѵ�.
  return 1 + numOfPrime(n-1);
}

