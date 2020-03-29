#include <iostream>
#include <cstring>

using namespace std;

int* dp;
int* stair;

int max(int a, int b)
{
	return a < b ? b : a;
}

int main() {
	int n, ans = 0;
	cin >> n;

	dp = new int[n + 1];
	stair = new int[n + 1];
	memset(dp, 0, sizeof(int) * (n + 1));
	stair[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> stair[i];
	}
	if (n < 3)
	{
		for (int i = 1; i <= n; i++)
		{
			ans += stair[i];
		}
	}
	else
	{
		dp[1] = stair[1];
		dp[2] = stair[1] + stair[2];
		for (int i = 3; i <= n; i++)
		{
			dp[i] = max(dp[i - 2], stair[i - 1] + dp[i - 3]) + stair[i];
		}
		ans = dp[n];
	}
	delete[] dp;
	delete[] stair;

	cout << ans << endl;

	return 0;
}
