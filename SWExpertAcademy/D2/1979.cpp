#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	int T, N, K;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N >> K;
		//W 초기화
		//map을 0으로 둘러 싼다
		int W[17][17] = { {0, } };
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cin >> W[i][j];
			}
		}

		//가로 확인
		int cnt = 0;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				int garo = 1;
				if (W[i][j] == 1)
				{
					if (W[i][j - 1] == 0)
					{
						int k;
						for (k = j + 1; k <= N; k++)
						{
							if (W[i][k] == 0) break;
							garo++;
						}
						j = k;
					}
					if (garo == K)
						cnt++;
				}
			}
		}
		//세로 확인
		for (int j = 1; j <= N; j++)
		{
			for (int i = 1; i <= N; i++)
			{
				int sero = 1;
				if (W[i][j] == 1)
				{
					if (W[i - 1][j] == 0)
					{
						int k;
						for (k = i + 1; k <= N; k++)
						{
							if (W[k][j] == 0) break;
							sero++;
						}
						i = k;
					}
					if (sero == K)
						cnt++;
				}
			}
		}

		cout << '#' << tc << ' ';
		cout << cnt << endl;
	}

	return 0;
}
