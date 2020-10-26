#pragma once
// 2020-10-11

template<typename T>
T max(T a, T b)
{
	// b < a ��� a�� ��ȯ�ϰ� �ƴ϶�� b�� ��ȯ�Ѵ�.
	return b > a ? a : b;
}

/*
�������� ������ ���� �Ķ���͸� �������� �� typenmae ��� class ����� ���� �ִ�.
typename�̶�� Ű����� C++98 ǥ���� ����� �� ����� �ʰ� ���Եƴ�.
�� ������ ���� �Ķ���͸� Ű���� class�� �����ؾ� �߱� ������ ������ typename ��� class�� ����� �� �ִ�.

�׷��� ���ø� max()�� ����ó�� �����ص� �ȴ�.

template<class T>
T max(T a, T b)
{
	return b > a ? a : b;
}

�ǹ̻� �� �Լ��� �ٸ� �� ���� ����. ���� ���⼭ class�� ����ϴ��� ���ø� ���ڷ� ��� �����̵� ����� �� �ִ�.
������ class�� ����ϸ� ������ �� �����Ƿ�(T�� Ŭ���������� �� �� �ִ� �� �ƴѵ���) typename�� ����ϴ� ���� ����.
Ŭ������ ����� �޸� typename  ��� Ű���� struct �� �� �� ����.
*/