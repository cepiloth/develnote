#include "fibo.h"

Cfibo::Cfibo(){
  memset(memo, 0, sizeof(memo));
}

int Cfibo::execute(int n){
	return fibonacci(n);
}

int Cfibo::fibonacci(int n){
	if (n <= 1) {
    return n;
  } else if(memo[n] != 0) {
    return memo[n];
  } else {
    return memo[n] = fibonacci(n-2) + fibonacci(n-1);
  }
}


