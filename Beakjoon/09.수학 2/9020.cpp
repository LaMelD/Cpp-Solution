#include <iostream>
#include <cstring>

using namespace std;

bool prime[10000];

int main()
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);;

	memset(prime, 0, sizeof(prime));
	prime[0] = true;
	prime[1] = true;
	for (int i = 2; i <= 10000; i++)
	{
		int tmp = 2;
		if (!prime[i])
		{
			while (i * tmp <= 10000)
			{
				prime[i * tmp] = true;
				tmp++;
			}
		}
	}

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		int input;
		cin >> input;
		int ans_1 = 0;
		int ans_2 = 0;
		for (int i = input / 2; i <= input; i++)
		{
			if (!prime[i] && !prime[input - i])
			{
				ans_1 = input - i;;
				ans_2 = i;
				break;
			}
		}
		cout << ans_1 << ' ' << ans_2 << endl;
	}

	return 0;
}
