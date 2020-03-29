#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(string s)
{
	int s_len = s.length();

	long long ret = 1;

	for (int i = 0; i < s_len; i++)
	{
		int mul = 3;
		//왼쪽 끝일 경우
		if (i == 0)
		{
			//왼쪽 끝과 그 오른쪽 문자가 같다면 *1이므로 continue
			if (s[i] == s[i + 1]) continue;
			//다르다면 *2
			mul = 2;
		}
		//오른쪽 끝일 경우
		else if (i == s_len - 1)
		{
			//오른쪽 끝과 그 왼쪽 문자가 같다면 *1이므로 continue
			if (s[i - 1] == s[i]) continue;
			//다르다면 *2
			mul = 2;
		}
		//나머지 경우
		else
		{
			//왼쪽과 중간이 같은 경우
			if (s[i - 1] == s[i])
			{
				mul -= 1;
				//모두 같은 경우
				if (s[i - 1] == s[i + 1]) continue;
			}
			//중간과 오른쪽이 같은 경우
			else if (s[i] == s[i + 1])
			{
				mul -= 1;
			}
			//왼쪽과 오른쪽이 같은 경우
			else if (s[i - 1] == s[i + 1])
			{
				mul -= 1;
			}
		}
		ret = (ret * mul) % 1000000007;
	}
	return (int)ret;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		string s;
		cin >> s;

		cout << '#' << test_case << " ";
		cout << solution(s) << endl;
	}
	return 0;
}
