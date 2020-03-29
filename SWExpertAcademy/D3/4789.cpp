#include <iostream>
#include <string>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		string s;
		cin >> s;
		int clap = s[0] - '0';

		int ans = 0;
		for (int i = 1; i < s.length(); i++)
		{
			int n = 0;
			int tmp = s[i] - '0';
			if (clap < i)
			{
				n = i - clap;
			}
			clap = clap + n + tmp;
			ans += n;
		}

		cout << '#' << tc << ' ';
		cout << ans << '\n';
	}

	return 0;
}
