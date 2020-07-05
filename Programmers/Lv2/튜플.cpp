# include <vector>
# include <string>
# include <algorithm>
# include <map>

using namespace std;

vector<string> split(string s, char c)
{
	vector<string> ret;
	string tmp = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == c)
		{
			ret.push_back(tmp);
			tmp = "";
		}
		else
		{
			tmp += s[i];
		}
	}
	ret.push_back(tmp);

	return ret;
}

string replace(string s, char from, char to)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == from)
		{
			s[i] = to;
		}
	}
	return s;
}

string lstrip(string s)
{
	string ret;
	bool is_start = false;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ' && !is_start)
		{
			continue;
		}
		is_start = true;
		ret += s[i];
	}

	return ret;
}

vector<int> solution(string s)
{
	vector<int> ans;

	vector<string> strs = split(s, '}');
	vector<vector<string>> number_set;

	for (int i = 0; i < strs.size(); i++)
	{
		if (strs[i].size() == 0)
		{
			continue;
		}
		string str = replace(strs[i], '{', ' ');
		str = replace(str, ',', ' ');
		str = lstrip(str);
		number_set.push_back(split(str, ' '));
	}

	sort(number_set.begin(), number_set.end(), [](vector<string> a, vector<string> b) {return a.size() < b.size(); });

	map<string, int> m;

	for (int i = 0; i < number_set.size(); i++)
	{
		for (int j = 0; j < number_set[i].size(); j++)
		{
			if (m.find(number_set[i][j]) == m.end())
			{
				m.insert(pair<string, int>(number_set[i][j], 0));
				ans.push_back(stoi(number_set[i][j]));
			}
		}
	}

	return ans;
}