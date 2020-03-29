#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> coin(n + 1, 0);
	vector<int> dp(k + 1, 0);

	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> coin[i];
	}

	//점화식을 만드는 단계가 중요
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (coin[i] <= j)
			{
				dp[j] = dp[j] + dp[j - coin[i]];
			}
		}
	}

	int ans = dp[k];

	cout << ans << endl;

	return 0;
}
