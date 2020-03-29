#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		int n, q;
		cin >> n >> q;
		vector<int> N(n + 1, 0);
		vector<int> L(q + 1, 0);
		vector<int> R(q + 1, 0);
		for (int i = 1; i <= q; i++)
		{
			cin >> L[i] >> R[i];
		}

		for (int i = 1; i <= q; i++)
		{
			for (int j = L[i]; j <= R[i]; j++)
			{
				N[j] = i;
			}
		}

		cout << '#' << tc;
		for (int i = 1; i <= n; i++)
		{
			cout << ' ' << N[i];
		}
		cout << '\n';
	}

	return 0;
}
