#include<vector>
#include<iostream>
#include<algorithm>
#include <functional>         // greater 사용 위해 필요  

using namespace std;

#include "irunnable.h"

class COvertime {
public:
	COvertime();
	
	int execute(int no,vector<int> works);

private:
	int noOverTime(int no,vector<int> works);
};

