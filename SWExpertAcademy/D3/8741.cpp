#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int solve(int n)
{
	int ret = 0;

	while (n != 0)
	{
		ret += n % 10;
		n = n / 10;
	}

	return ret;
}

int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		string input;
		string ans = "";

		for (int i = 0; i < 3; i++)
		{
			cin >> input;
			ans += toupper(input[0]);
		}

		cout << '#' << tc << ' ';
		cout << ans << endl;
	}

	return 0;
}
