#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) 
{
	//map을 모두 0으로 초기화
	vector<vector<int>> v(m + 1, vector<int>(n + 1, 0));

	//웅덩이 부분을 -1로 설정
	for (int i = 0; i < puddles.size(); i++)
	{
		v[puddles[i][0]][puddles[i][1]] = -1;
	}

	//웅덩이를 만나기 전까지 y축을 1로 설정
	for (int i = 1; i <= m; i++)
	{
		if (v[i][1] == -1)
		{
			break;
		}
		v[i][1] = 1;
	}

	//웅덩이를 만나기 전까지 x축을 1로 설정
	for (int i = 1; i <= n; i++)
	{
		if (v[1][i] == -1)
		{
			break;
		}
		v[1][i] = 1;
	}

	for (int i = 2; i <= m; i++)
	{
		for (int j = 2; j <= n; j++)
		{
			//현재 좌표의 값이 웅덩이면 다음으로
			if (v[i][j] == -1)
			{
				continue;
			}

			//왼쪽이 웅덩이면
			if (v[i - 1][j] == -1)
			{
				v[i][j] = v[i][j - 1];
			}
			//위쪽이 웅덩이면
			else if (v[i][j - 1] == -1)
			{
				v[i][j] = v[i - 1][j];
			}
			//둘다 아니라면
			else
			{
				v[i][j] = (v[i - 1][j] + v[i][j - 1]) % 1000000007;
			}
		}
	}

	//오른쪽 아래 좌표의 값을 리턴
	return v[m][n];
}
