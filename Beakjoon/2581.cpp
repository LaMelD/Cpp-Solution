#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int prime[10001];
	memset(prime, 0, sizeof(prime));
	prime[0] = true;
	prime[1] = true;
	for (int i = 2; i <= 10001; i++)
	{
		int tmp = 2;
		if (!prime[i])
		{
			while (i * tmp <= 10001)
			{
				prime[i * tmp] = true;
				tmp++;
			}
		}
	}

	int m, n;
	cin >> m >> n;
	int sum = 0;
	int mini = 0;
	for (int i = m; i <= n; i++)
	{
		if (!prime[i])
		{
			if (sum == 0)
			{
				mini = i;
			}

			sum += i;
		}
	}

	if (sum == 0)
	{
		cout << "-1" << endl;
	}
	else
	{
		cout << sum << '\n' << mini << endl;
	}

	return 0;
}
