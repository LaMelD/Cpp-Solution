#include <iostream>
#include <vector>

using namespace std;

void make_snail(vector<vector<int>>& v, int& n, int num, int i, int j)
{
	v[i][j] = num;

	if ((j + 1) < n && v[i][j + 1] == 0)
	{
		make_snail(v, n, num + 1, i, j + 1);
	}
	else if ((i + 1) < n && v[i + 1][j] == 0)
	{
		make_snail(v, n, num + 1, i + 1, j);
	}
	else if ((j - 1) >= 0 && v[i][j - 1] == 0)
	{
		make_snail(v, n, num + 1, i, j - 1);
	}
	else if ((i - 1) >= 0 && v[i - 1][j] == 0)
	{
		make_snail(v, n, num + 1, i - 1, j);
	}
}

int main()
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);

	int T;
	cin >> T;

	for (int tc = 1; tc < T; tc++)
	{
		int n;
		cin >> n;
		vector<vector<int>> v(n, vector<int>(n, 0));

		make_snail(v, n, 1, 0, 0);

		cout << '#' << tc << '\n';
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << v[i][j];
				if (j != (n - 1))
				{
					cout << ' ';
				}
			}
			cout << '\n';
		}
	}
}
