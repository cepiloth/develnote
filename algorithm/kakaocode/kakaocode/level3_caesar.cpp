
#include "level3_caesar.h"

string caesar(string s, int n)
{
	n = n % 26;

	cout << "n 은 " << n << endl;
	cout << "소문자 은 " << 'a' - 'z' << endl;
	cout << "대문자 은 " << 'A' -'Z' << endl;

	string answer = "";
	int size = s.size();
	for(int i=0; i<size; i++) {
		char ch = s[i];
		// 공백 문자 처리
		if(ch == ' ') {
			answer.push_back(' ');
			continue;
		}
		// 현재 문자의 아스키 코드와 입력받을 n 크기 만큼 더 한다.
		unsigned char tmp = ch + n;

		// ch 아스키 값이 대문자인지 소문자인지 확인
		if('a' <= ch && ch <= 'z') {
			// 앞서 계산한 tmp 값이 아스키 글자 소문자 z 범위를 넘는다면 보정 한다.
			if (tmp > 'z')
				tmp = 'a' + (tmp - 'z') - 1;
		}
		else if ('A' <= ch && ch <= 'Z') {
			// 앞서 계산한 tmp 값이 아스키 글자 대문자 z 범위를 넘는다면 보정 한다.
			if (tmp > 'Z')
				tmp = 'A' + (tmp - 'Z') - 1;
		}
		answer.push_back(tmp);
	}
	return answer;
}