#include <iostream>
#include <vector>

using namespace std;

int main() 
{
	int n, T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> n;
		vector<long long> dp = { 0, 1, 1, 1, 2 };
		if (n <= 4)
		{
			cout << dp[n] << endl;
			continue;
		}

		for (int i = 5; i <= n; i++)
		{
			dp.push_back(dp[i - 1] + dp[i - 5]);
		}
		cout << dp[n] << endl;
	}

	return 0;
}
