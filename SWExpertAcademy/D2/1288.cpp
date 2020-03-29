#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		int n = 0;
		cin >> n;

		bool visit[10] = { 0, };
		int cnt = 0;

		int sum = n;
		int ans = 1;
		while (1)
		{
			int tmp = sum;
			while (1)
			{
				int mod = tmp % 10;
				tmp = tmp / 10;
				if (!visit[mod])
				{
					visit[mod] = true;
					cnt++;
				}

				if (cnt == 10)
				{
					break;
				}

				if (tmp == 0)
				{
					break;
				}
			}

			if (cnt == 10)
			{
				break;
			}
			sum += n;
			ans++;
		}

		cout << '#' << tc << ' ';
		cout << ans * n << '\n';
	}

	return 0;
}
