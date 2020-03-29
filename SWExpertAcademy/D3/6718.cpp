#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		int d;
		cin >> d;
		d = d / 100;

		int cnt = 0;
		while (d != 0)
		{
			d = d / 10;
			cnt++;
		}


		cout << '#' << tc << ' ';
		if (cnt < 5)
		{
			cout << cnt << '\n';
		}
		else
		{
			cout << '5' << '\n';
		}
	}

	return 0;
}
