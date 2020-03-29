//전형적인 knapsack문제
#include <iostream>

using namespace std;

int dp[21][10001] = { { 0, } };

int max(int a, int b)
{
	return a < b ? b : a;
}

int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		int n, limit;
		cin >> n >> limit;
		int score[1001] = { 0, };
		int kcal[1001] = { 0, };

		for (int i = 1; i <= n; i++)
		{
			cin >> score[i] >> kcal[i];

		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= limit; j++)
			{
				if (kcal[i] <= j)
				{
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - kcal[i]] + score[i]);
				}
				else
				{
					dp[i][j] = dp[i - 1][j];
				}
			}
		}

		cout << '#' << tc << ' ';
		cout << dp[n][limit] << endl;
	}

	return 0;
}
