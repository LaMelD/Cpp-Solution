#include <string>
#include <vector>
#include <iostream>

using namespace std;

//여러가지 방법을 생각했으나
//대부분의 방법들이 규칙을 만족시키지 못했다
//이것 저것 해보다가 발견한 방법이다
//이유를 설명하긴 힘들 듯 하다
int solution(int n)
{
	//2차원 배열 dp를 (n + 1)*(n + 1) 크기로 만든다
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

	//0번째 행을 모두 1로 초기화 시키고
	//나머지는 0으로 유지한다
	for (int i = 0; i <= n; i++)
	{
		dp[0][i] = 1;
	}
	
	//y = x 그래프를 넘지 않는 dp[n][n]의 최단 거리의 갯수를 구한다
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}

	int ans = dp[n][n];

	return ans;
}
