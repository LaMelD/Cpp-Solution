#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		string s;
		cin >> s;

		int garo, sero;
		sero = 5;
		garo = s.length() * 4 + 1;

		int idx = 0;
		for (int i = 0; i < sero; i++)
		{
			for (int j = 0; j < garo; j++)
			{
				if (i == 0 || i == 4)
				{
					if (j % 4 == 2)
					{
						cout << '#';
					}
					else
					{
						cout << '.';
					}
				}
				else if (i == 1 || i == 3)
				{
					if (j % 2 == 1)
					{
						cout << '#';
					}
					else
					{
						cout << '.';
					}
				}
				else
				{
					if (j % 4 == 2)
					{
						cout << s[idx++];
					}
					else if (j % 4 == 0)
					{
						cout << '#';
					}
					else
					{
						cout << '.';
					}
				}
			}
			cout << '\n';
		}
	}

	return 0;
}
