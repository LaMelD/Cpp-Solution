#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		int n;
		cin >> n;
		vector<int> score(n + 1);
		bool dp[101][10002] = { 0, };
		dp[0][0] = true;
		int maximum = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> score[i];
			maximum += score[i];
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= maximum; j++)
			{
				if (dp[i - 1][j])
				{
					dp[i][j] = dp[i - 1][j];
					dp[i][j + score[i]] = true;
				}
			}
		}

		int cnt = 0;
		for (int i = 0; i <= maximum; i++)
		{
			if (dp[n][i])
			{
				cnt++;
			}
		}

		cout << '#' << tc << ' ';
		cout << cnt << '\n';
	}
	
	return 0;
}
