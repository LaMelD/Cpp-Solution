#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);

	int origin;
	cin >> origin;
	int n = origin;

	int cnt = 0;
	int n_right, n_left, new_right;

	while (1)
	{
		n_right = n % 10;
		n_left = n / 10;
		new_right = (n_left + n_right) % 10;
		n = n_right * 10 + new_right;
		cnt++;
		if (n == origin) break;
	}
	cout << cnt << "\n";
}
