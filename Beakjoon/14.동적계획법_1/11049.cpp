#include <iostream>
#include <vector>
#define INT_MAX 2147483647

using namespace std;

struct node {
	int r = 0;
	int c = 0;
};

int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int n;
	cin >> n;
	vector<node> matrix(n + 1);
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++)
	{
		cin >> matrix[i].r >> matrix[i].c;
	}

	for (int d = 1; d <= n; d++)
	{
		for (int i = 1; i + d <= n; i++)
		{
			int j = i + d;
			dp[i][j] = INT_MAX;

			for (int m = i; m < j; m++)
			{
				dp[i][j] = min(dp[i][j], dp[i][m] + dp[m + 1][j] + matrix[i].r * matrix[m].c * matrix[j].c);
			}
		}
	}

	cout << dp[1][n] << endl;

	return 0;
}
