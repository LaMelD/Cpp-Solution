#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int k, n;
		cin >> k >> n;

		if (n == 1)
		{
			cout << '1' << endl;
		}
		else
		{
			int apt[15][15];
			int i, j;
			for (int i = 0; i < 15; i++)
			{
				apt[0][i] = i;
				apt[i][1] = 1;
			}
			for (int i = 1; i <= k; i++)
			{
				for (int j = 2; j <= n; j++)
				{
					apt[i][j] = apt[i][j - 1] + apt[i - 1][j];
				}
			}
			cout << apt[k][n] << endl;
		}
	}

	return 0;
}
