#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		int P, Q, R, S, W;
		cin >> P >> Q >> R >> S >> W;

		int Left = W * P;
		int Right = 0;
		if (W < R)
		{
			Right = Q;
		}
		else
		{
			Right = Q + ((W - R) * S);
		}

		int ans = Left < Right ? Left : Right;

		cout << '#' << tc << ' ';
		cout << ans << '\n';
	}

	return 0;
}
