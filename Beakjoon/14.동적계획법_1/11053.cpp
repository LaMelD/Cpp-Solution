#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int* dp;
int* A;

int max(int a, int b)
{
	return a < b ? b : a;
}

int main() {
	int n;
	cin >> n;
	dp = new int[n + 1];
	A = new int[n + 1];
	dp[0] = A[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> A[i];
	}

        //생각하기 어려웠다
        //이러한 유형의 문제도 문제해결 방법을 알아두는 것이 좋을 듯 하다
	int k;
	int ans = dp[0];
	for (int i = 1; i <= n; i++)
	{
		k = 0;
		for (int j = 0; j < i; j++)
		{
			if (A[j] < A[i])
			{
				if (dp[k] < dp[j])
				{
					k = j;
				}
			}
		}
		dp[i] = dp[k] + 1;
		ans = max(ans, dp[i]);
	}

	cout << ans << endl;

	return 0;
}
