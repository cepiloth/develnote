#include<vector>
#include<iostream>
using namespace std;

#include "irunnable.h"

class Cfibo : public iRunnable {
public:
	Cfibo();
	
	int execute(int n);
	int execute(long n){
		return 0;
	}

private:
	int fibonacci(int n);
	int memo[1000]; // check to stacksize!!
};

