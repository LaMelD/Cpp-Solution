#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
	string ans = "";
	vector<string> sv;
	string tmp;

	//공백을 기준으로 문자열 쪼개기
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ')
		{
			sv.push_back(tmp);
			tmp = "";
			continue;
		}

		tmp += s[i];
	}
	sv.push_back(tmp);
	//공백을 기준으로 sv에 문자열이 들어가있다

	//문자열의 갯수
	for (int i = 0; i < sv.size(); i++)
	{
		//j번째 문자열의 길이
		for (int j = 0; j < sv[i].size(); j++)
		{
			//맨 앞자리 확인 및 변경
			if (j == 0)
			{
				if (sv[i][j] < 'a') continue;

				if (sv[i][j] > 'Z') sv[i][j] = sv[i][j] - 'a' + 'A';
			}
			//이 외의 자리 변경
			else
			{
				if (sv[i][j] < 'a') sv[i][j] = sv[i][j] - 'A' + 'a';
			}
		}
		//ans에 더한다
		ans += sv[i];
		ans += " ";
	}
	//마지막 공백을 지운다
	ans.pop_back();

	return ans;
}
