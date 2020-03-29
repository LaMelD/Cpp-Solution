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

		int a = s[s.length() - 1] - '0';

		cout << '#' << tc << ' ';
		if (a % 2 == 0)
		{
			cout << "Even\n";
		}
		else
		{
			cout << "Odd\n";
		}
	}

	return 0;
}
