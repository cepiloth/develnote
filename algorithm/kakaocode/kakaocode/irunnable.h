#ifndef __IRUNNABLE_H__
#define __IRUNNABLE_H__

class iRunnable {
public:
	// �̰��� ���� ��ũ�ϼ��ε�
	// ������ c++ �����̶� �����ϰ� ���� 
	virtual int execute(int n) = 0;
	virtual int execute(long n) = 0;
};

#endif __IRUNNABLE_H__