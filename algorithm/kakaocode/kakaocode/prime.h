#include<vector>
#include<iostream>
using namespace std;

#include "irunnable.h"

class CPrime : public iRunnable {
public:
	CPrime();
	
	int execute(int n);
	int execute(long n)
	{
		return 0;
	}

private:
	int numOfPrime(int n);
};

