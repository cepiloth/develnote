
#include "level3_caesar.h"

string caesar(string s, int n)
{
	n = n % 26;

	cout << "n �� " << n << endl;
	cout << "�ҹ��� �� " << 'a' - 'z' << endl;
	cout << "�빮�� �� " << 'A' -'Z' << endl;

	string answer = "";
	int size = s.size();
	for(int i=0; i<size; i++) {
		char ch = s[i];
		// ���� ���� ó��
		if(ch == ' ') {
			answer.push_back(' ');
			continue;
		}
		// ���� ������ �ƽ�Ű �ڵ�� �Է¹��� n ũ�� ��ŭ �� �Ѵ�.
		unsigned char tmp = ch + n;

		// ch �ƽ�Ű ���� �빮������ �ҹ������� Ȯ��
		if('a' <= ch && ch <= 'z') {
			// �ռ� ����� tmp ���� �ƽ�Ű ���� �ҹ��� z ������ �Ѵ´ٸ� ���� �Ѵ�.
			if (tmp > 'z')
				tmp = 'a' + (tmp - 'z') - 1;
		}
		else if ('A' <= ch && ch <= 'Z') {
			// �ռ� ����� tmp ���� �ƽ�Ű ���� �빮�� z ������ �Ѵ´ٸ� ���� �Ѵ�.
			if (tmp > 'Z')
				tmp = 'A' + (tmp - 'Z') - 1;
		}
		answer.push_back(tmp);
	}
	return answer;
}