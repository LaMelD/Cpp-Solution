//기본적인 knapsack 풀이 
//시간복잡도 O(2^n)
#include <iostream>
#include <vector>

using namespace std;

struct node {
	int w = 0;
	int v = 0;
};

int max(int a, int b)
{
	return a < b ? b : a;
}

int getMAXvalue(vector<node>& w, int& n, int k, int idx)
{
	if (idx > n)
		return 0;

	int notput = getMAXvalue(w, n, k, idx + 1);
	int put = 0;

	if (k - w[idx].w >= 0)
	{
		put = getMAXvalue(w, n, k - w[idx].w, idx + 1) + w[idx].v;
	}

	int ret = max(notput, put);

	return ret;
}

int main()
{
	int N, K;
	cin >> N >> K;
	vector<node> stuff(N + 1);

	for (int i = 1; i <= N; i++)
	{
		cin >> stuff[i].w >> stuff[i].v;
	}

	int ans = getMAXvalue(stuff, N, K, 1);

	cout << ans << endl;

	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//DP로 푸는 knapsack 풀이
//시간복잡도 O(N * K)
#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b)
{
	return a < b ? b : a;
}

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> w(n + 1, 0);
	vector<int> v(n + 1, 0);
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

	for (int i = 1; i <= n; i++)
	{
		cin >> w[i] >> v[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			if (w[i] <= j)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	int ans = dp[n][k];

	cout << ans << endl;

	return 0;
}
