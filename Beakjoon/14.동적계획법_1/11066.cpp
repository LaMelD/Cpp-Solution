#include <iostream>
#include <cstring>
#define INT_MAX 2147483647

using namespace std;

int** dp;
int* sum;

int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++)
	{
		int n, input;
		cin >> n;
		dp = new int* [n + 1];
		dp[0] = new int[n + 1];
		memset(dp[0], 0, sizeof(int) * (n + 1));

		sum = new int[n + 1];
		memset(sum, 0, sizeof(int) * (n + 1));
		for (int i = 1; i <= n; i++)
		{
			cin >> input;
			sum[i] = sum[i - 1] + input;
			dp[i] = new int[n + 1];
			memset(dp[i], 0, sizeof(int) * (n + 1));
		}

		for (int d = 1; d <= n; d++)
		{
			for (int i = 1; i + d <= n; i++)
			{
				int j = i + d;
				dp[i][j] = INT_MAX;

				for (int m = i; m < j; m++)
				{
					dp[i][j] = min(dp[i][j], dp[i][m] + dp[m + 1][j] + sum[j] - sum[i - 1]);
				}
			}
		}

		cout << dp[1][n] << endl;

		delete[] sum;
		for (int i = 0; i <= n; i++)
		{
			delete[] dp[i];
		}
		delete[] dp;
	}
	return 0;
}
