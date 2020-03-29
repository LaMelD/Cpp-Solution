#include <iostream>
#include <cstring>
#define MAX 1073741824

using namespace std;

int* dp;

int min(int a, int b)
{
	return a < b ? a : b;
}

int is_can_div(int a, int b)
{
	return a % b == 0;
}

int main() {
	int n;
	int ans = 0;
	cin >> n;
	dp = new int[n + 1];
	memset(dp, 0, sizeof(int) * (n + 1));

	//2부터 확인한다
	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + 1;
		
		//2로 나눌 수 있다면
		if (is_can_div(i, 2))
		{
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}

		//3으로 나눌 수 있다면
		if (is_can_div(i, 3))
		{
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
	}

	ans = dp[n];

	delete[] dp;

	cout << ans << endl;

	return 0;
}
