#include <iostream>
#include <string>
#include <vector>

using namespace std;

int max(int a, int b)
{
	return a < b ? b : a;
}

int main() {
	int* dp;
	int* A;
	int n;
	cin >> n;
	dp = new int[n + 1];
	A = new int[n + 1];
	dp[0] = 0;
	A[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> A[i];
	}

	int ans = -1001;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = max(A[i], A[i] + dp[i - 1]);

		ans = max(ans, dp[i]);
	}

	cout << ans << endl;

	return 0;
}
