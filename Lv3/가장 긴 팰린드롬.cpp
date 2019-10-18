#include <iostream>
#include <string>

using namespace std;

int s_size;
string str;

int max(int a, int b)
{
	return a < b ? b : a;
}

int palindrome(int left, int right) 
{
	int ret = 0;

	//left와 right가 각각 0이상 s_size미만이 아니면 0을 리턴
	if (left < 0 || right >= s_size) return 0;

	//left와 right가 같다면
	if (str[left] == str[right]) 
	{
		//ret + 2하고 left에 -1하고 right에 +1 하여 펠린드롬을 콜한다
		ret += palindrome(left - 1, right + 1) + 2;
	}

	return ret;
}

int solution(string s) 
{
	s_size = s.size();
	str = s;
	int ans = 1;
	int i = 1;
	while (1) {
		if (i == s_size - 1) break;

		if ((s_size - 1 - i) * 2 - 1 < ans) break;

		//aba 인 경우
		if (s[i - 1] == s[i + 1]) {
			ans = max(palindrome(i - 1, i + 1) + 1, ans);
		}

		//abba 인 경우
		if (s[i] == s[i + 1]) {
			ans = max(palindrome(i, i + 1), ans);
		}

		if (ans == s_size) break;
		i++;
	}

	return ans;
}
