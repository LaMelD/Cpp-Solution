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
		int n;
		cin >> n;

		n = n / 2;

		long long ret = (long long)n * (long long)n;

		cout << '#' << tc << ' ';
		cout << ret << '\n';
	}

	return 0;
}
