#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve(vector<vector<int>>& map, int i, int j, int cnt, string ret, vector<string>& s)
{
	if (i < 0 || 3 < i || j < 0 || 3 < j)
	{
		return;
	}

	char tmp = '0' + map[i][j];
	ret.push_back(tmp);

	if (cnt >= 6)
	{
		s.push_back(ret);
		return;
	}

	//동
	solve(map, i, j + 1, cnt + 1, ret, s);
	//서
	solve(map, i, j - 1, cnt + 1, ret, s);
	//남
	solve(map, i + 1, j, cnt + 1, ret, s);
	//북
	solve(map, i - 1, j, cnt + 1, ret, s);
}

int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		vector<vector<int>> map(4, vector<int>(4, 0));
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cin >> map[i][j];
			}
		}

		vector<string> store;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				solve(map, i, j, 0, "", store);
			}
		}

		sort(store.begin(), store.end());
		store.erase(unique(store.begin(), store.end()), store.end());

		cout << '#' << tc << ' ';
		cout << store.size() << '\n';
	}

	return 0;
}
