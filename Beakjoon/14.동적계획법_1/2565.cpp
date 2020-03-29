#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max(int, int);
int solution(int, vector<vector<int>>);
int LIS(int, vector<int>);
//sort를 위한 overroading
bool operator<(vector<int> a, vector<int> b)
{
	return a[0] < b[0];
}

int main() {
	//n :: 전깃줄의 갯수
	int n;
	cin >> n;
	vector<vector<int>> wire = { { 0, 0 } };
	int a, b;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		wire.push_back({ a, b });
	}

	int ans = solution(n, wire);

	cout << ans << endl;

	return 0;
}

int max(int a, int b)
{
	return a < b ? b : a;
}

//전깃줄이 교차하는 조건(a,i :: A전봇대, b,j :: B전봇대)
//(a < i) && (b > j) 또는
//(a > i) && (b < j) 인 경우 교차한다
//따라서 wire를 i를 기준으로 오름차순으로 정렬한 뒤
//B에 대해서 LIS(Longest Increasing Subsequence) 값을 알아내고
//n에서 빼줌으로써 몇 개의 전깃줄을 뺏는지 알 수 있다
int solution(int n, vector<vector<int>> wire)
{
	sort(wire.begin(), wire.end());

	vector<int> B(n + 1);
	for (int i = 1; i <= n; i++)
	{
		B[i] = wire[i][1];
	}

	int k = LIS(n, B);

	int ret = n - k;

	return ret;
}

//가장 긴 증가하는 부분수열(LIS) 알고리즘
//Time complex = O(n^2)
int LIS(int n, vector<int> Arr)
{
	vector<int> dp(n + 1, 0);
	int k;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		k = 0;
		for (int j = 0; j < i; j++)
		{
			if (Arr[j] < Arr[i])
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

	return ans;
}
