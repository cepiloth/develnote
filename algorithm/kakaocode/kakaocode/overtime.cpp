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
		// 내림 차순 정렬을 하면서 가장 큰 업무량을 제거 
		sort(works.begin(), works.end(), greater<int>());
		works[0] -= 1;
	}
  
	for(int i=0;i<size;i++)
		answer = answer + works[i] * works[i];
  
	return answer;
}
