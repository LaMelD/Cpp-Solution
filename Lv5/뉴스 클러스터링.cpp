#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int power(int a, int b)
{
	int ret = 1;

	for (int i = 0; i < b; i++)
	{
		ret *= a;
	}

	return ret;
}

bool is_alpha(char a)
{
	if ('a' <= a && a <= 'z')
	{
		return true;
	}

	if ('A' <= a && a <= 'Z')
	{
		return true;
	}

	return false;
}

int solution(string str1, string str2) 
{
	priority_queue<int, vector<int>, greater<int>> s1;
	priority_queue<int, vector<int>, greater<int>> s2;
	const int cmp = power(2, 8);
	int tmp;

	for (int i = 0; i < str1.length() - 1; i++)
	{
		//두개 모두 알파벳일 경우
		if (is_alpha(str1[i]) && is_alpha(str1[i + 1]))
		{
			str1[i] = toupper(str1[i]);
			str1[i + 1] = toupper(str1[i + 1]);
			tmp = str1[i] * cmp + str1[i + 1];
			s1.push(tmp);
		}
		else
		{
			continue;
		}
	}

	for (int i = 0; i < str2.length() - 1; i++)
	{
		if (is_alpha(str2[i]) && is_alpha(str2[i + 1]))
		{
			str2[i] = toupper(str2[i]);
			str2[i + 1] = toupper(str2[i + 1]);
			tmp = str2[i] * cmp + str2[i + 1];
			s2.push(tmp);
		}
		else
		{
			continue;
		}
	}

	int intersection = 0;
	int sum = s1.size() + s2.size();

	if (sum == 0)
	{
		return 65536;
	}

	while (!s1.empty() && !s2.empty())
	{
		if (s1.top() == s2.top())
		{
			s1.pop();
			s2.pop();
			intersection++;
		}
		else if (s1.top() < s2.top())
		{
			s1.pop();
		}
		else
		{
			s2.pop();
		}
	}
	
	sum = sum - intersection;


	int answer = intersection * 65536 / sum;
	return answer;
}
