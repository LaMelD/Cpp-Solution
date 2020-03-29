#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		int RGB[3][10] = { { 0, } };
		int r = 0, g = 0, b = 0;
		int i, j;
		string input, rgb;
		cin >> input;
		cin >> rgb;

		for (int i = 0; i < 9; i++)
		{
			switch (rgb[i])
			{
			case 'R' :
				RGB[0][input[i] - '0']++;
				r++;
				break;
			case 'G' :
				RGB[1][input[i] - '0']++;
				g++;
				break;
			case 'B' :
				RGB[2][input[i] - '0']++;
				b++;
				break;
			}
		}

		cout << '#' << tc << ' ';

		if (r % 3 != 0 || g % 3 != 0 || b % 3 != 0)
		{
			cout << "Continue" << '\n';
			continue;
		}

		bool flag = false;

		for (i = 0; i < 3; i++)
		{
			int cnt = 0;
			for (j = 1; j <= 7; j++)
			{
				if (RGB[i][j] == 0)
				{
					continue;
				}

				if (RGB[i][j] >= 3)
				{
					RGB[i][j] = RGB[i][j] % 3;
				}

				switch (RGB[i][j])
				{
				case 1 :
					if (RGB[i][j + 1] >= 1 && RGB[i][j + 2] >= 1)
					{
						RGB[i][j] -= 1;
						RGB[i][j + 1] -= 1;
						RGB[i][j + 2] -= 1;
					}
					else
					{
						flag = true;
					}
					break;
				case 2 :
					if (RGB[i][j + 1] >= 2 && RGB[i][j + 2] >= 2)
					{
						RGB[i][j] -= 2;
						RGB[i][j + 1] -= 2;
						RGB[i][j + 2] -= 2;
					}
					else
					{
						flag = true;
					}
					break;
				}

				if (flag)
				{
					break;
				}
			}

			if (RGB[i][8] % 3 != 0 || RGB[i][9] % 3 != 0)
			{
				flag = true;
			}

			if (flag)
			{
				break;
			}
		}

		if (flag)
		{
			cout << "Continue\n";
		}
		else
		{
			cout << "Win\n";
		}
	}

	return 0;
}
