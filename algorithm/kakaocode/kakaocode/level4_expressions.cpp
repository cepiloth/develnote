#include "level4.h"


// [LEVEL4] 숫자의 표현 
int expressions(int testCase)
{
	int count = 0;
	int sum = 0;

	// 완전 탐색에 가까움
	// 부분합 문제인거 같음

	// 초기문 0, 조건문 testCase
	for(int startNumber=0; startNumber<testCase; startNumber++) {

		// sum 의 값을 시작 index 값으로 초기화 한다.
		sum = startNumber;

		// next 의 값을 startNumber +1 로 설정하고 합계를 구한다.
		for(int next=startNumber+1; next <testCase; next++) {
			sum += next;

			if(sum == testCase) {
				// 내부 합계가 testCase 와 같으므로 count 를 증가
				count++;
				break;
			}
			else if(sum > testCase) {
				// 내부 합계가 testCase 의 값을 넘으면 더이상 계산 할필요가 없음 으로 종료
				break;
			}
		}
	}
	return ++count;
}
