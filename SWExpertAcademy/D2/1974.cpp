#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

bool garoline(int W[9][9])
{
	bool flag[10];
	for (int i = 0; i < 9; i++)
	{
		memset(flag, 0, sizeof(flag));
		for (int j = 0; j < 9; j++)
		{
			if (flag[W[i][j]])
			{
				return false;
			}
			flag[W[i][j]] = true;
		}
	}
	return true;
}

bool seroline(int W[9][9])
{
	bool flag[10];
	for (int i = 0; i < 9; i++)
	{
		memset(flag, 0, sizeof(flag));
		for (int j = 0; j < 9; j++)
		{
			if (flag[W[j][i]])
			{
				return false;
			}
			flag[W[j][i]] = true;
		}
	}
	return true;
}

bool _3x3(int W[9][9])
{
	bool flag[10];
	for (int i = 0; i < 9; i += 3)
	{
		for (int j = 0; j < 9; j += 3)
		{
			memset(flag, 0, sizeof(flag));
			for (int a = i; a < i + 3; a++)
			{
				for (int b = j; b < j + 3; b++)
				{
					if (flag[W[a][b]])
					{
						return false;
					}
					flag[W[a][b]] = true;
				}
			}
		}
	}
	return true;
}

int main()
{
	int T;
	cin >> T;
	int W[9][9];
	bool flag[10];
	for (int tc = 1; tc <= T; tc++)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cin >> W[i][j];
			}
		}

		cout << '#' << tc << ' ';
		if (seroline(W) && garoline(W) && _3x3(W))
		{
			cout << '1' << endl;
		}
		else
		{
			cout << '0' << endl;
		}
	}

	return 0;
}
