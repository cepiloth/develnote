#include<vector>
#include<iostream>
#include<algorithm>
#include <functional>         // greater ��� ���� �ʿ�  

using namespace std;

#include "irunnable.h"

class COvertime {
public:
	COvertime();
	
	int execute(int no,vector<int> works);

private:
	int noOverTime(int no,vector<int> works);
};

