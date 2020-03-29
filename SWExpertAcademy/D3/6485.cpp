#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		int n, p;
		cin >> n;
		vector<int> A(n + 1, 0);
		vector<int> B(n + 1, 0);
		for (int i = 1; i <= n; i++)
		{
			cin >> A[i] >> B[i];
		}
		cin >> p;
		vector<int> C(p + 1, 0);
		vector<int> ans(p + 1, 0);
		for (int i = 1; i <= p; i++)
		{
			cin >> C[i];
			for (int j = 1; j <= n; j++)
			{
				if (A[j] <= C[i] && C[i] <= B[j])
				{
					ans[i]++;
				}
			}
		}

		cout << '#' << tc;
		for (int i = 1; i <= p; i++)
		{
			cout << ' ' << ans[i];
		}

		cout << '\n';
	}

	return 0;
}
