#include "jumpcase.h"

CJumpCase::CJumpCase(){
}
	
int CJumpCase::execute(int n) {
	return jumpCase(n);
}

int CJumpCase::jumpCase(int n){
	  // n == 0 �̸� ��� ĭ�� ���� �������� ����
  if(n == 0)
    return 1;
  // �̰� ��Ÿ��� ����ó��.. �̷����ϸ� �Ƿ� ���� �ʽ��ϴ�.
  else if(n < 0)
    return 0;
  
  return jumpCase(n-1) + jumpCase(n-2);
}

