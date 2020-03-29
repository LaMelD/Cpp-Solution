#include <iostream>
#include <vector>

using namespace std;

int getdate(int a, int b) {
	int cnt = 0;
	switch (a) {
	case 12: cnt += 30;
	case 11: cnt += 31;
	case 10: cnt += 30;
	case 9: cnt += 31;
	case 8: cnt += 31;
	case 7: cnt += 30;
	case 6: cnt += 31;
	case 5: cnt += 30;
	case 4: cnt += 31;
	case 3: cnt += 28;
	case 2: cnt += 31;
	case 1: cnt += 0;
	}
	cnt = cnt + b;

	return cnt;
}

int main()
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		int a1, b1, a2, b2;
		cin >> a1 >> b1 >> a2 >> b2;
		int sum1 = getdate(a1, b1);
		int sum2 = getdate(a2, b2);

		int ans = sum2 - sum1 + 1;

		cout << '#' << tc << ' ';
		cout << ans << '\n';
	}
}
