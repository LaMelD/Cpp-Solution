#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int prime[2001] = { 0, };
int A[999] = { 0 };

void make_prime_arr()
{
	prime[0] = true;
	prime[1] = true;
	int k = 0;
	for (int i = 2; i <= 1200; i++)
	{
		int tmp = 2;
		if (!prime[i])
		{
			A[k++] = i;
			while (i * tmp <= 1200)
			{
				prime[i * tmp] = true;
				tmp++;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);

	int T;
	cin >> T;
	make_prime_arr();

	for (int tc = 1; tc <= T; tc++)
	{
		int n;
		cin >> n;

		int limit = 0;
		while (1)
		{
			if (A[limit] > n)
				break;

			limit++;
		}

		int cnt = 0;
		for (int i = 0; i < limit; i++)
		{
			for (int j = i; j < limit; j++)
			{
				if (A[i] + A[j] > n)
				{
					break;
				}

				for (int k = j; k < limit; k++)
				{
					if (A[i] + A[j] + A[k] > n)
					{
						break;
					}

					if (A[i] + A[j] + A[k] == n)
					{
						cnt++;
						break;
					}
				}
			}
		}

		cout << '#' << tc << ' ';
		cout << cnt << endl;
	}
}
