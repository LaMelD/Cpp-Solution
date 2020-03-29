#include <iostream>

typedef long long ll;

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		ll n;
		cin >> n;

		ll ans = -1;
		for (ll i = 1; i <= n; i++)
		{
			if (i * i * i > n)
				break;

			if (n == i * i * i)
			{
				ans = i;
				break;
			}
		}

		cout << '#' << tc << ' ';
		cout << ans << '\n';
	}

	return 0;
}
