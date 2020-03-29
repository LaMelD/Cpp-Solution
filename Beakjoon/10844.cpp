#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<vector<int>> dp(n, vector<int>(10));
	for (int i = 1; i < 10; i++)
	{
		dp[0][i] = 1;
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
			{
				dp[i][j] = dp[i - 1][j + 1];
			}
			else if (j == 9)
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < 10; i++)
	{
		ans = (ans + dp[n - 1][i]) % 1000000000;
	}

	cout << ans << endl;

	return 0;
}
