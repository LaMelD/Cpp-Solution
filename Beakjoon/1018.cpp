#include <iostream>
#include <string>

using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int N, M;
	cin >> N >> M;

	string nm[51];

	for (int i = 0; i < N; i++)
	{
		cin >> nm[i];
	}

	int mini = 66;
	for (int i = 0; i + 7 < N; i++)
	{
		for (int j = 0; j + 7 < M; j++)
		{
			int change = 0;
			for (int x = 0; x < 8; x++)
			{
				for (int y = 0; y < 8; y++)
				{
					if (x % 2 == 0)
					{
						if (y % 2 == 0)
						{
							if (nm[i + x][j + y] == 'W')
							{
								change++;
							}
						}
						else
						{
							if (nm[i + x][j + y] == 'B')
							{
								change++;
							}
						}
					}
					else
					{
						if (y % 2 == 0)
						{
							if (nm[i + x][j + y] == 'B')
							{
								change++;
							}
						}
						else
						{
							if (nm[i + x][j + y] == 'W')
							{
								change++;
							}
						}
					}
				}
			}
			mini = min(mini, change);

			change = 0;
			for (int x = 0; x < 8; x++)
			{
				for (int y = 0; y < 8; y++)
				{
					if (x % 2 == 0)
					{
						if (y % 2 == 0)
						{
							if (nm[i + x][j + y] == 'B')
							{
								change++;
							}
						}
						else
						{
							if (nm[i + x][j + y] == 'W')
							{
								change++;
							}
						}
					}
					else
					{
						if (y % 2 == 0)
						{
							if (nm[i + x][j + y] == 'W')
							{
								change++;
							}
						}
						else
						{
							if (nm[i + x][j + y] == 'B')
							{
								change++;
							}
						}
					}
				}
			}
			mini = min(mini, change);
		}
	}

	cout << mini << endl;

	return 0;
}
