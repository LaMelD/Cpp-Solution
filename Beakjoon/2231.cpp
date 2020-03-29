#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int n = stoi(s);
	int create = 0;

	int num;
	for (int i = s.length() * 9; i > 0; i--)
	{
		num = n - i;
		if (num < 1) continue;

		int tmp = num;
		int div = num;
		while (div != 0)
		{
			tmp += div % 10;
			div = div / 10;
		}

		if (tmp == n)
		{
			create = num;
			break;
		}
	}

	cout << create << endl;

	return 0;
}
