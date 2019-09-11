#ifndef __IRUNNABLE_H__
#define __IRUNNABLE_H__

class iRunnable {
public:
	// 이건좀 오버 테크니션인듯
	// 어차피 c++ 연습이라 생각하고 하자 
	virtual int execute(int n) = 0;
	virtual int execute(long n) = 0;
};

#endif __IRUNNABLE_H__