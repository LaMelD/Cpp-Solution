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
		int n, a, b;
		long long ans = 0;

		cin >> n >> a >> b;
		
		if (a <= b)
		{
			if (n > 2)
			{
				n -= 2;
				ans = ((long long)b - (long long)a + 1) * (long long)n - ((long long)n - 1);
			}
			else
			{
				if (n == 1 && a == b || n == 2)
				{
					ans = 1;
				}
			}
		}

		cout << '#' << tc << ' ';
		cout << ans << '\n';
	}

	return 0;
}
