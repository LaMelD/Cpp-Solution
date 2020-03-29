#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int* dp;
int* wine;

int max(int a, int b)
{
	return a < b ? b : a;
}

int main() {
	int n;
	cin >> n;
	dp = new int[n + 1];
	wine = new int[n + 1];
	memset(dp, 0, sizeof(int) * (n + 1));
	memset(wine, 0, sizeof(int) * (n + 1));
	for (int i = 1; i <= n; i++)
	{
		cin >> wine[i];
	}

	int ans = 0;
	if (n < 3)
	{
		for (int i = 1; i <= n; i++)
		{
			ans += wine[i];
		}
	}
	else
	{
		dp[0] = 0;
		dp[1] = wine[1];
		dp[2] = dp[1] + wine[2];
                //maxi의 사용에서 생각하기 힘들었다(반례를 생각하는데 시간이 걸렸다)
                //0부터 i - 3까지의 최대값을 maxi에 저장한다
		int maxi = dp[0];
		for (int i = 3; i <= n; i++)
		{
                        //maxi값을 갱신한다
			maxi = max(maxi, dp[i - 3]);
                        //와인[i - 1] + (dp[0]부터 dp[i - 3)까지의 최대값)과 dp[i - 2]값을 비교한다
			dp[i] = max(dp[i - 2], wine[i - 1] + maxi) + wine[i];
		}
		for (int i = 1; i <= n; i++)
		{
			ans = max(ans, dp[i]);
		}
	}

	delete[] wine;
	delete[] dp;

	cout << ans << endl;

	return 0;
}
