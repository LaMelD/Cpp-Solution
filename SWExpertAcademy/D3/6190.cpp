#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b)
{
	return a < b ? b : a;
}

//단조 증가 수인지 확인하는 절차에서 시간복잡도가 중요하다
//to_string을 사용하면 시간초과가 발생한다
bool is_increasing(int num)
{
	int a = num % 10;
	num = num / 10;
	int b = num % 10;
	while (num != 0)
	{
		if (a < b)
		{
			return false;
		}
		a = b;
		num = num / 10;
		b = num % 10;
	}

	return true;
}

int main()
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		int n;
		cin >> n;

		vector<int> A(n + 1, 0);
		for (int i = 1; i <= n; i++)
		{
			cin >> A[i];
		}

		int ans = -1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				int test = A[i] * A[j];

				if (test < ans) continue;

				if (is_increasing(test))
				{
					ans = max(ans, test);
				}
			}
		}

		cout << '#' << tc << ' ';
		cout << ans << '\n';
	}

	return 0;
}
