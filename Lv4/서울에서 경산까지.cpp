#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int** dp;

int max(int a, int b)
{
	return a > b ? a : b;
}

int solution(int K, vector<vector<int>> travel) {
	int i, j;
	int N = travel.size();

        //동적 할당
	dp = new int*[N];
	for (i = 0; i < N; i++)
	{
                //아래방법도 가능하다
		//*(dp + i) = new int[K + 1];
		dp[i] = new int[K + 1];
                //배열 초기화
                memset(dp[i], 0, sizeof(int) * (K + 1));
	}
        
        //첫번째를 방문한다
	for (j = 1; j <= K; j++)
	{
		dp[0][j] = max(travel[0][0] > j ? 0 : travel[0][1], travel[0][2] > j ? 0 : travel[0][3]);
	}

        //두번째 부터 반복문 시작
	for (i = 1; i < N; i++)
	{
		for (j = 1; j <= K; j++)
		{
                        //시간이 넘어야하고
                        //방문한 기록이 존재해야한다
                        //0이면 이전에 방문하지 않았다는 표시
			if (j >= travel[i][0] && dp[i - 1][j - travel[i][0]] != 0)
			{
				dp[i][j] = dp[i - 1][j - travel[i][0]] + travel[i][1];
			}

			if (j >= travel[i][2] && dp[i - 1][j - travel[i][2]] != 0)
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j - travel[i][2]] + travel[i][3]);
			}
		}
	}

	int ret = dp[N - 1][K];

        //힙 메모리 해제
	for (i = 0; i < N; i++)
	{
		delete[] dp[i];
	}
	delete[] dp;

	return ret;
}
