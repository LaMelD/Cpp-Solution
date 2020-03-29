#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		int n, ans;
		cin >> n;

		if (n % 2 == 0)
		{
			ans = (n + 1) / 2;
			ans = ans * (-1);
		}
		else
		{
			ans = (n + 1) / 2;
		}

		cout << '#' << tc << ' ';
		cout << ans << endl;
	}
}
