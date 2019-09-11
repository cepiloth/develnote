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
			// 소수가 아니라면 0 반환
			return 0 + numOfPrime(n-1);
			break;
		}
	}
  
  // 소수라면 1을 리턴하고 재귀 한다.
  return 1 + numOfPrime(n-1);
}

