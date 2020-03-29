#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		int A, B, C;
		cin >> A >> B >> C;

		int small = A < B ? A : B;

		int ans = C / small;

		cout << '#' << tc << ' ';
		cout << ans << '\n';
	}

	return 0;
}
