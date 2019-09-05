#include <string>
#include <iostream>

using namespace std;

bool solution(string s)
{
	//'('을 만나면 cnt++
	//')'을 만나면 cnt--
	//cnt값이 음수라면 return false
	//마지막까지 확인했을 때 cnt == 0 이라면 return true
	int cnt = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(') cnt++;
		else if (s[i] == ')') cnt--;

		if (cnt < 0) return false;
	}
	if (cnt == 0) return true;
	return false;
}
