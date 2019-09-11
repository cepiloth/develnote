#include "jumpcase.h"

CJumpCase::CJumpCase(){
}
	
int CJumpCase::execute(int n) {
	return jumpCase(n);
}

int CJumpCase::jumpCase(int n){
	  // n == 0 이면 모든 칸에 도착 했음으로 종료
  if(n == 0)
    return 1;
  // 이건 안타까운 에러처리.. 이렇게하면 실력 늘지 않습니다.
  else if(n < 0)
    return 0;
  
  return jumpCase(n-1) + jumpCase(n-2);
}

