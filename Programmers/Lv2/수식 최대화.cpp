# include <vector>
# include <string>

typedef long long ll;

using namespace std;

vector<string> split(string e)
{
	vector<string> ret;
	string s = "";
	for (int i = 0; i < e.length(); i++)
	{
		if (e[i] == '+' || e[i] == '-' || e[i] == '*')
		{
			ret.push_back(s);
			s = e[i];
			ret.push_back(s);
			s = "";
		}
		else
		{
			s += e[i];
		}
	}
	ret.push_back(s);
	return ret;
}

ll getValue(vector<string> exp, vector<string> priority)
{
	for (int i = 0; i < priority.size(); i++)
	{
		int j = 0;
		while (1)
		{
			if (exp.size() == 1)
			{
				break;
			}
			if (exp.size() <= j)
			{
				break;
			}

			if (exp[j] == priority[i])
			{
				ll val1 = stoll(exp[j - 1]);
				ll val2 = stoll(exp[j + 1]);
				if (priority[i] == "+")
				{
					exp[j - 1] = to_string(val1 + val2);
				}
				else if (priority[i] == "-")
				{
					exp[j - 1] = to_string(val1 - val2);
				}
				else if (priority[i] == "*")
				{
					exp[j - 1] = to_string(val1 * val2);
				}
				exp.erase(exp.begin() + j, exp.begin() + j + 2);
			}
			else
			{
				j++;
			}
		}
	}

	return abs(stoll(exp[0]));
}

long long solution(string expression) 
{
	vector<string> num_exps = split(expression);
	vector<vector<string>> exp_priority = 
	{
		{"+", "-", "*"},
		{"+", "*", "-"},
		{"-", "*", "+"},
		{"-", "+", "*"},
		{"*", "-", "+"},
		{"*", "+", "-"}
	};

	ll max = 0;
	for (int i = 0; i < exp_priority.size(); i++)
	{
		ll tmp = getValue(num_exps, exp_priority[i]);
		max = max < tmp ? tmp : max;
	}

	return max;
}