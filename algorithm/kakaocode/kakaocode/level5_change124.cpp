
#include "level5.h"

string change124(int no)
{
	string answer = "";
	int a;

	while(no > 0){
		a = no % 3;
		no = no / 3;
		if (a == 0){
			no -= 1;
		}
		answer = "412"[a] + answer;
	}

	return answer;
}