#include<vector>
#include<iostream>
using namespace std;

#include "irunnable.h"

class Collatz : public iRunnable{
public:
	Collatz();
	
	int execute(int n);
	int execute(long n);

private:
	int count;
};