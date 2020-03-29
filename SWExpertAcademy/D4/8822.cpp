#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);

	int T;
	cin >> T;

	//문제를 잘 읽어야 한다
	//문제에 중간값이라고 명시되어 있지만
	//본인은 평균이라고 이해를 해버렸다
	//다시 한번 강조한다 문제를 잘 읽어야 한다
	for (int tc = 1; tc <= T; tc++)
	{
		int n, x;
		cin >> n >> x;

		int ret = 0;

		int mini = 2;
		int maxi = 2 * n - 2;

		if (mini <= x && x <= maxi)
		{
			ret = 1;
		}

		cout << '#' << tc << ' ' << ret << '\n';
	}

	return 0;
}
