#include <iostream>
#include <string>

using namespace std;

int solve(string sen)
{
	int ans = 11;
	for (int i = 1; i <= 10; i++)
	{
		bool flag_1 = true;
		for (int j = 0; j < i; j++)
		{
			if (sen[j] != sen[i + j])
			{
				flag_1 = false;
				break;
			}
		}

		if (flag_1)
		{
			bool flag_2 = true;
			for (int j = 0; j < 30; j++)
			{
				if (sen[j % i] != sen[j])
				{
					flag_2 = false;
					break;
				}
			}

			if (flag_2)
			{
				return i;
			}
		}
	}

	return 0;
}

int main()
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		string sen;
		cin >> sen;

		int ans = solve(sen);

		cout << '#' << tc << ' ';
		cout << ans << endl;
	}
}
