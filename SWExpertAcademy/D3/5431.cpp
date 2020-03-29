#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		int n, k;
		cin >> n >> k;
		vector<bool> submit(n + 1, 0);

		for (int i = 1; i <= k; i++)
		{
			int tmp;
			cin >> tmp;
			submit[tmp] = !submit[tmp];
		}

		cout << '#' << tc;
		for (int i = 1; i <= n; i++)
		{
			if (!submit[i])
			{
				cout << ' ' << i;
			}
		}
		cout << '\n';
	}

	return 0;
}
