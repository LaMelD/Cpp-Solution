#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) 
{
	string ans = "";
	int maxi;
	int mini;
	int tmp;
	string s_tmp;
	for (int i = 0; i < s.length(); i++) 
	{
		s_tmp = "";
		int j;
		if (s[i] == ' ') continue;

		//'-'로 시작할때 숫자 추출
		if (s[i] == '-') 
		{
			i++;
			for (j = i; j < s.length(); j++) 
			{
				if (s[j] == ' ') break;
				
				s_tmp += s[j];
			}
			tmp = stoi(s_tmp) * -1;
		}
		//양수일 때 숫자 추출
		else 
		{
			for (j = i; j < s.length(); j++) 
			{
				if (s[j] == ' ') break;
				
				s_tmp += s[j];
			}
			tmp = stoi(s_tmp);
		}

		//첫 maxi, mini 설정
		//i가 0 또는 1이 되는 순간은 한번이다
		if (i == 0 || i == 1) 
		{
			maxi = tmp;
			mini = tmp;
		}
		else 
		{
			if (maxi < tmp) maxi = tmp;
			if (mini > tmp) mini = tmp;
		}
		
		i = j;
	}
	ans += to_string(mini);
	ans += " ";
	ans += to_string(maxi);

	cout << ans << endl;

	return ans;
}
