
#include<iostream>
#include<vector>

#include "gcd.h"
#include "fibo.h"
#include "prime.h"
#include "Collatz.h"
#include "jumpcase.h"
#include "overtime.h"
#include "CNlcm.h"

#include "level3_caesar.h"
#include "level4.h"

#include "codeforce.h"
// ToDo... 구글 테스트 러너나 테스팅 붙이기
void testGCD(int a, int b) {
	CGcd gcd;
	vector<int> answer = gcd.gcdlcm(a,b);

	cout << answer[0] << " " << answer[1] << endl; 
}

void testFibo(int n) {
	Cfibo fibo;
	long long ans = fibo.execute(n);
	cout << ans << endl;
}

void testPrime(int n) {
	CPrime prime;
	int ans = prime.execute(n);
	cout << ans << endl;
}

void testCollartz(long n) {
	Collatz collatz;
	int ans = collatz.execute(n);
	cout << ans << endl;
}

void testJumpCase(int n) {
	CJumpCase jumpcase;
	int ans = jumpcase.execute(n);
	cout << ans << endl;
}

void testOverTime() {

	int no = 4;
	vector<int> works(3);
	works.push_back(4);
	works.push_back(3);
	works.push_back(3);

	COvertime overtime;
	int ans = overtime.execute(no, works);
	cout << ans << endl;
}

void testNlcm() {
	vector<int> test;
	test.push_back(2);
	test.push_back(6);
	test.push_back(8);
	test.push_back(14);

	CNlcm nlcm;

	long long ans = nlcm.execute(test);
	cout << ans << endl;
}

void test_level3_caesar() {

	string text = "abcdefghijklmnopqrstuvwxyz";
	string Text2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int testNo = 18;

	string testAnswer = caesar(text, testNo);

	cout<<testAnswer << endl;

	testAnswer = caesar(Text2, testNo);

	cout<<testAnswer << endl;
}

const inline void inpect(int solution, int answer) {
	if (solution == answer) {
		cout << "TEST SUCCESS : " << solution << endl;
	} else {
		cout << "TEST FAIL : " << solution << endl;
	}
}

void test_level4_expressions() {
	int testNo = 15;
	int testAnswer = expressions(testNo);
	inpect(5, testAnswer);

	expressions(155);
	inpect(5, testAnswer);
	// 아래는 테스트로 출력해 보기 위한 코드입니다.
}

void test_level4_bestSet() {
	int n=3, s=13;
	vector<int> test= bestSet(n,s);

	// 아래는 테스트로 출력해 보기 위한 코드입니다.
	for(int i=0; i<test.size(); i++)
		cout << test[i] << " ";
}

int old_main() {
	testGCD(3, 12);

	testFibo(10);

	testPrime(10);

	testCollartz(6);

	testJumpCase(4);

	testOverTime();

	testNlcm();

	test_level3_caesar();

	test_level4_expressions();

	test_level4_bestSet();
	return 0;
}