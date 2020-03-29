#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> solve(int n)
{
	vector<vector<int>> ret;

	for (int i = 0; i < n; i++)
	{
		vector<int> v;
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
			{
				v.push_back(1);
			}
			else if (j == i)
			{
				v.push_back(1);
			}
			else
			{
				v.push_back(ret[i - 1][j - 1] + ret[i - 1][j]);
			}
		}
		ret.push_back(v);
	}

	return ret;
}

int main()
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		int n;
		cin >> n;

		vector<vector<int>> ret = solve(n);
		string ans = "";

		for (int i = 0; i < ret.size(); i++)
		{
			for (int j = 0; j < ret[i].size(); j++)
			{
				ans += to_string(ret[i][j]);
				ans += ' ';
			}
			ans.pop_back();
			ans += '\n';
		}

		cout << '#' << tc << endl;
		cout << ans;
	}
}
