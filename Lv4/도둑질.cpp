#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}

//1. 첫번째 집을 털은 경우 마지막 집을 털 수 없다
//2. 첫번째 집을 안 턴 경우 마지막 집을 털 수 있다(단편적으로)
int solution(vector<int> money) {
	int m_size = money.size();
	int ret = 0;
	vector<int> dp(m_size + 2, 0);
	dp[2] = money[0];
	//1번 테스트
	for (int i = 1; i < m_size - 1; i++)
	{
                //dp[i+2]에 넣어줌으로 다음 반복은 현재 결과에 영향을 받지 않고 진행 가능하다
		if (dp[i] > dp[i - 1])
		{
			dp[i + 2] = dp[i] + money[i];
		}
		else
		{
			dp[i + 2] = dp[i - 1] + money[i];
		}
		ret = max(ret, dp[i + 2]);
	}

	//2번 테스트를 진행하기 위해 dp배열 초기화
	dp.clear();
	dp.assign(m_size + 2, 0);

	//2번 테스트
	dp[3] = money[1];
	for (int i = 2; i < m_size; i++)
	{
                //dp[i+2]에 넣어줌으로 다음 반복은 현재 결과에 영향을 받지 않고 진행 가능하다
		if (dp[i] > dp[i - 1])
		{
			dp[i + 2] = dp[i] + money[i];
		}
		else
		{
			dp[i + 2] = dp[i - 1] + money[i];
		}
		ret = max(ret, dp[i + 2]);
	}

	return ret;
}


//예시
//1, 2, 3, 4
//3, 1, 1, 5, 1
//1, 1, 4, 5, 4
