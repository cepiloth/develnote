#include<vector>
#include<iostream>
using namespace std;

#include "irunnable.h"

class CJumpCase : public iRunnable {
public:
	CJumpCase();
	
	int execute(int n);
	int execute(long n){
		return 0;
	}

private:
	int jumpCase(int n);
};

