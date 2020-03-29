#include <iostream>
#include <cstring>

using namespace std;

bool prime[1000001];

int main()
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);;

	memset(prime, 0, sizeof(prime));
	prime[0] = true;
	prime[1] = true;
	for (int i = 2; i <= 1000001; i++)
	{
		int tmp = 2;
		if (!prime[i])
		{
			while (i * tmp <= 1000001)
			{
				prime[i * tmp] = true;
				tmp++;
			}
		}
	}

	int m, n;
	cin >> m >> n;
	int sum = 0;
	for (int i = m; i <= n; i++)
	{
		if (!prime[i])
		{
			cout << i << '\n';
		}
	}

	return 0;
}
