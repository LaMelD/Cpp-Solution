#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results)
{
	vector<vector<int>> W(n + 1, vector<int>(n + 1, 0));

	int i, j, k;

	for (i = 0; i < results.size(); i++)
	{
		//승리
		W[results[i][0]][results[i][1]] = 1;
		//패배
		W[results[i][1]][results[i][0]] = -1;
	}

	//승자승, 패자패 기반으로 W를 완성시킨다
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (W[i][j] != 0) 
			{
				//예1
				//i선수에게 승리한 j선수
				//i선수에게 패배한 k선수
				//따라서 j선수는 k선수에게 항상 승리한다
				//예2
				//i선수에게 패배한 j선수
				//i선수에게 승리한 k선수
				//따라서 j선수는 k선수에게 항상 패배한다
				for (k = 1; k <= n; k++) 
				{
					if (W[i][j] == -W[i][k]) 
					{
						W[j][k] = -W[i][j];
					}
				}
			}
		}
	}

	int cnt, answer = 0;
	for (i = 1; i < n + 1; i++) 
	{
		cnt = 0;

		//i == j인 경우는 0이기 때문에
		//W[i]에서 0의 갯수를 count하여 1이면
		//순위가 확정된다
		for (j = 1; j < n + 1; j++) 
		{
			if (W[i][j] == 0) cnt++;
		}

		if (cnt == 1) answer++;
	}

	return answer;
}
