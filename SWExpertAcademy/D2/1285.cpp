#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		int n = 0;
		cin >> n;

		int mini = 1000002;
		int cnt = 0;

		for (int i = 0; i < n; i++) 
		{
			int input;
			cin >> input;
			if (input < 0)
			{
				input = input * (-1);
			}

			if (input < mini)
			{
				mini = input;
				cnt = 1;
			}
			else if (input == mini)
			{
				cnt++;
			}
		}


		cout << '#' << tc << ' ';
		cout << mini << ' ' << cnt << '\n';
	}

	return 0;
}
