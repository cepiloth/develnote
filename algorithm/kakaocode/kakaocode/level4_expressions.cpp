#include "level4.h"


// [LEVEL4] ������ ǥ�� 
int expressions(int testCase)
{
	int count = 0;
	int sum = 0;

	// ���� Ž���� �����
	// �κ��� �����ΰ� ����

	// �ʱ⹮ 0, ���ǹ� testCase
	for(int startNumber=0; startNumber<testCase; startNumber++) {

		// sum �� ���� ���� index ������ �ʱ�ȭ �Ѵ�.
		sum = startNumber;

		// next �� ���� startNumber +1 �� �����ϰ� �հ踦 ���Ѵ�.
		for(int next=startNumber+1; next <testCase; next++) {
			sum += next;

			if(sum == testCase) {
				// ���� �հ谡 testCase �� �����Ƿ� count �� ����
				count++;
				break;
			}
			else if(sum > testCase) {
				// ���� �հ谡 testCase �� ���� ������ ���̻� ��� ���ʿ䰡 ���� ���� ����
				break;
			}
		}
	}
	return ++count;
}
