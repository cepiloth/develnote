#include "gcd.h"

int CGcd::gcd(int a, int b) {
  return (a % b == 0 ? b : gcd(b,a%b));
}

vector<int> CGcd::gcdlcm(int a,int b)
{
  int ret = gcd(a,b);
  // cout << "최소공배수 " << ret << endl;
  vector<int> answer;
  answer.push_back(ret);
  answer.push_back(a*b/ret);
  //cout << " " << answer[1] << endl;
	return answer;
}
