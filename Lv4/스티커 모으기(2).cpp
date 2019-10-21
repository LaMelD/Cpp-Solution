#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> sticker)
{
	int n = sticker.size();
	int ret = 0;
	if (n > 3)
	{
		vector<int> dp(n + 1, 0);
		//첫번째 스티커를 선택 -> 마지막 스티커 선택 불가
		dp[0] = sticker[0];
		dp[1] = sticker[1];
		dp[2] = sticker[2] + dp[0];
		ret = max(dp[1], dp[2]);
		for (int i = 3; i < n - 1; i++)
		{
			dp[i] = max(dp[i - 2], dp[i - 3]) + sticker[i];
			ret = max(ret, dp[i]);
		}

		//첫번째 스티커를 선택하지 않음 마지막 스티커 선택 가능
		dp[0] = 0;
		dp[1] = sticker[1];
		dp[2] = sticker[2];
		ret = max(ret, dp[1]);
		ret = max(ret, dp[2]);
		for (int i = 3; i < n; i++)
		{
			dp[i] = max(dp[i - 2], dp[i - 3]) + sticker[i];
			ret = max(ret, dp[i]);
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			ret = max(ret, sticker[i]);
		}
	}

	return ret;
}
