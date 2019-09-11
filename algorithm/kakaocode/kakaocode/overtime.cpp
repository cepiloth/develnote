#include "overtime.h"

COvertime::COvertime(){
}
	
int COvertime::execute(int no,vector<int> works){
	return noOverTime(no, works);
}

int COvertime::noOverTime(int no,vector<int> works)
{
	int answer = 0;
	int size = works.size();
  
	while(no--)
	{
		// ���� ���� ������ �ϸ鼭 ���� ū �������� ���� 
		sort(works.begin(), works.end(), greater<int>());
		works[0] -= 1;
	}
  
	for(int i=0;i<size;i++)
		answer = answer + works[i] * works[i];
  
	return answer;
}
