#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	int max = a < b ? b : a;
	int min = a < b ? a : b;

	while (min != 0)
	{
		int tmp = max % min;
		max = min;
		min = tmp;
	}

	return max;
}

//여러가지 반례가 존재하여 구하는데 애를 먹었다
int main()
{
	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++)
	{
		int m, n, x, y;
		cin >> m >> n >> x >> y;

		int tmp_y = x % n == 0 ? n : x % n;
		for (int i = 0; i < n; i++)
		{
			if (tmp_y == y) break;
			x += m;
			if ((tmp_y + m) % n == 0)
			{
				tmp_y = n;
			}
			else
			{
				tmp_y = (tmp_y + m) % n;
			}
		}

		int lcm = m * n / gcd(m, n);

		if (lcm < x)
		{
			cout << "-1" << endl;
		}
		else
		{
			cout << x << endl;
		}
	}

	return 0;
}
