#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	int T;
	cin >> T;
	int n;
	int change[8] = { 50000, 10000, 5000,1000, 500, 100, 50, 10 };
	int cnt[8];
	for (int tc = 1; tc <= T; tc++)
	{
		memset(cnt, 0, sizeof(cnt));
		cin >> n;
		for (int i = 0; i < 8; i++)
		{
			cnt[i] = n / change[i];
			n = n % change[i];
		}
		cout << '#' << tc << endl;
		for (int i = 0; i < 8; i++)
		{
			cout << cnt[i];
			if (i != 7)
				cout << ' ';
		}
		cout << endl;
	}

	return 0;
}
