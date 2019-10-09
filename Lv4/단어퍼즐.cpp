//dfs로 풀었을 경우
//시간초과 뻥!
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define INT_MAX 2147483647

using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

bool is_fit(string t, string str, int t_len, int str_len, int idx)
{
	for (int i = 0; i < str_len; i++)
	{
		if (idx >= t_len)
		{
			return false;
		}

		if (t[idx++] != str[i])
		{
			return false;
		}
	}

	return true;
}

void dfs(vector<string>& strs, string& t, int& t_len, int idx, int cnt, int& ret)
{
	if (idx > t_len)
	{
		return;
	}

	if (idx == t_len)
	{
		ret = min(ret, cnt);
		return;
	}

	if (cnt > ret)
	{
		return;
	}

	for (int i = 0; i < strs.size(); i++)
	{
		if (is_fit(t, strs[i], t_len, strs[i].length(), idx))
		{
			dfs(strs, t, t_len, strs[i].length() + idx, cnt + 1, ret);
		}
	}
}

int solution(vector<string> strs, string t)
{
	int len = t.length();

	sort(strs.begin(), strs.end(), [](string a, string b)
	{
		return a.length() > b.length();
	}
	);

	int ret = INT_MAX;

	dfs(strs, t, len, 0, 0, ret);

	if (ret == INT_MAX)
	{
		ret = -1;
	}

	return ret;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//dp로 풀었을 경우
//통과하였다
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

bool is_fit(string& t, string& str, int& str_len, int idx)
{
	for (int i = str_len - 1; i >= 0; i--)
	{
		if (idx < 0)
		{
			return false;
		}

		if (t[idx--] != str[i])
		{
			return false;
		}
	}

	return true;
}

int solution(vector<string> strs, string t)
{
	int t_len = t.length();
	int setdefault = t_len + 1;

	vector<int> dp(t_len);

	for (int i = 0; i < t_len; i++)
	{
		dp[i] = setdefault;

		for (int j = 0; j < strs.size(); j++)
		{
			int tmp = strs[j].length();
			if (is_fit(t, strs[j], tmp, i))
			{
				tmp = i - tmp;
				if (tmp < 0)
				{
					dp[i] = 1;
				}
				else
				{
					dp[i] = min(dp[i], dp[tmp] + 1);
				}
			}
		}
	}

	int ret = dp.back();

	if (ret == setdefault)
	{
		return -1;
	}

	return ret;
}
