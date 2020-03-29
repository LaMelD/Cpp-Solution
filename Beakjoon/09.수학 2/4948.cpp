#include <iostream>
#include <cstring>

using namespace std;

bool prime[300000];

int main()
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);;

	memset(prime, 0, sizeof(prime));
	prime[0] = true;
	prime[1] = true;
	for (int i = 2; i <= 300000; i++)
	{
		int tmp = 2;
		if (!prime[i])
		{
			while (i * tmp <= 300000)
			{
				prime[i * tmp] = true;
				tmp++;
			}
		}
	}

	int n;
	while (1)
	{
		cin >> n;
		if (n == 0) break;

		int  ans = 0;
		for (int i = n + 1; i <= 2 * n; i++)
		{
			if (!prime[i])
			{
				ans++;
			}
		}

		cout << ans << endl;
	}

	return 0;
}
