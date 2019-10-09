#include <iostream>
#include <vector>
#include <string>
#define INTMAX +2147483647
#define INTMIN -2147483647

using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

int max(int a, int b)
{
	return a < b ? b : a;
}

int solution(vector<string> arr)
{
	int n = arr.size();
	
	//i부터 j까지의 최대값을 저장
	vector<vector<int>> dpMax(n, vector<int>(n, INTMIN));
	//i부터 j까지의 최소값을 저장
	vector<vector<int>> dpMin(n, vector<int>(n, INTMAX));

	//초기값 dp[i][i]를 설정
	for (int i = 0; i < n; i += 2)
	{
		int num = 0;
		for (int j = 0; j < arr[i].length(); j++)
		{
			num *= 10;
			int tmp = arr[i][j] - '0';
			num += tmp;
		}

		dpMax[i][i] = num;
		dpMin[i][i] = num;
	}

	//묶어서 dp값을 만든다
	for (int dist = 2; dist < n; dist += 2)
	{
		for (int i = 0; i + dist < n; i += 2)
		{
			int j = i + dist;

			for (int k = i + 1; k < j; k += 2)
			{
				//이번에 확인할 묶음의 중간 기호가 - 일 경우
				if (arr[k] == "-")
				{
					//dp[i][j]값과 (큰값 - 작은값)을 비교한다
					dpMax[i][j] = max(dpMax[i][j], dpMax[i][k - 1] - dpMin[k + 1][j]);
					//dp[i][j]값과 (작은값 - 큰값)을 비교한다
					dpMin[i][j] = min(dpMin[i][j], dpMin[i][k - 1] - dpMax[k + 1][j]);
				}
				//이번에 확인할 묶음의 중간 기호가 + 일 경우
				else
				{
					//dp[i][j]값과 (큰값 + 큰값)을 비교한다
					dpMax[i][j] = max(dpMax[i][j], dpMax[i][k - 1] + dpMax[k + 1][j]);
					//dp[i][j]값과 (작은값 + 작은값)을 비교한다
					dpMin[i][j] = min(dpMin[i][j], dpMin[i][k - 1] + dpMin[k + 1][j]);
				}
			}
		}
	}
	
	//최종적으로 0부터 (n - 1)까지의 최대값을 리턴한다
	int ret = dpMax[0][n - 1];

	return ret;
}
