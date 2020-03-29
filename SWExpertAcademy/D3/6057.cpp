#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		int n, m;
		cin >> n >> m;

		vector<vector<bool>> W(n + 1, vector<bool>(n + 1, false));
		for (int i = 0; i < m; i++)
		{
			int x, y;
			cin >> x >> y;
			W[x][y] = true;
			W[y][x] = true;
		}

		cout << '#' << tc << ' ';

		//정점의 갯수가 3개 미만 또는 간선의 수가 3개 미만이면 
		//삼각형의 갯수는 0
		if (n < 3 || m < 3)
		{
			cout << "0\n";
			continue;
		}

		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				for (int k = j + 1; k <= n; k++)
				{
					if (W[i][j] && W[i][k] && W[j][k])
					{
						ans++;
					}
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
