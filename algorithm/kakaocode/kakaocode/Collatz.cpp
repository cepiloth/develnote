
#include "Collatz.h"

Collatz::Collatz() {
	this->count = 0;
};

// 이건좀 오버 테크니션인듯
int Collatz::execute(int n){
	return 0;
}

int Collatz::execute(long n){
	int count = 0;  
	while(n > 1) {
    if (n % 2 == 0) {
		n = n / 2;
    }
    else {
      n = n * 3 + 1;
    }

    count++;

    if(count == 500) {
			count = -1;
			break;
		}
	}
  
	return count;
}