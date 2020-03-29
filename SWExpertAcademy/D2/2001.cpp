#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solve(int n, int m, int arr[15][15], int ai, int aj)
{
	int ret = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			ret += arr[ai + i][aj + j];
		}
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
		int arr[15][15] = { {0,}, };
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int input;
				cin >> input;
				arr[i][j] = input;
			}
		}

		int limit = n - m;
		int max = 0;
		for (int i = 0; i <= limit; i++)
		{
			for (int j = 0; j <= limit; j++)
			{
				int tmp = solve(n, m, arr, i, j);
				max = max > tmp ? max : tmp;
			}
		}

		cout << '#' << tc << ' ';
		cout << max << endl;
	}
}
