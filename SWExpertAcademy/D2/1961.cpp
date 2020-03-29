#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <functional>

using namespace std;

int main()
{
	int T;
	cin >> T;
	int n;
	//원본
	int W[7][7];
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> n;
		//각각 W를 시계 방향으로 90도 180도 270도 회전한 배열
		int W_rot[3][7][7];
		//입력
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> W[i][j];
			}
		}
		
		int tmp = n - 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				W_rot[0][i][j] = W[tmp - j][i];
				W_rot[1][i][j] = W[tmp - i][tmp -j];
				W_rot[2][i][j] = W[j][tmp - i];
			}
		}

		cout << '#' << tc << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < n; k++)
				{
					cout << W_rot[j][i][k];
				}
				if (j != 2)
					cout << ' ';
			}
			cout << endl;
		}
	}

	return 0;
}
