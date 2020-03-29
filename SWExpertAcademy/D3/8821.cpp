#include <iostream>
#include <string>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		string input;
		cin >> input;

		bool number[10] = { 0, };

		for (int i = 0; i < input.length(); i++)
		{
			number[input[i] - '0'] = !number[input[i] - '0'];
		}

		int ans = 0;
		for (int i = 0; i < 10; i++)
		{
			if (number[i])
			{
				ans++;
			}
		}

		cout << '#' << tc << ' ' << ans << '\n';
	}
}
