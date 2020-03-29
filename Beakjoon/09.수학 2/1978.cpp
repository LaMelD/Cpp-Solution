#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int prime[1001];
	memset(prime, 0, sizeof(prime));
	prime[0] = true;
	prime[1] = true;
	for (int i = 2; i <= 1000; i++)
	{
		int tmp = 2;
		if (!prime[i])
		{
			while (i * tmp <= 1000)
			{
				prime[i * tmp] = true;
				tmp++;
			}
		}
	}

	int ans = 0;
	int input;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		if (!prime[input])
		{
			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}
