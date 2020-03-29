#include <iostream>
#include <vector>
#include <string>

using namespace std;

int max(int a, int b)
{
	return a < b ? b : a;
}

int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		int n;
		cin >> n;

		vector<int> block(n + 1);
		for (int i = 1; i <= n; i++)
		{
			cin >> block[i];
		}
		int to_up = 0;
		int to_down = 0;
		int b_block = block[1];
		for (int i = 2; i <= n; i++)
		{
			if (b_block < block[i])
			{
				to_up = max(to_up, block[i] - b_block);
			}
			else
			{
				to_down = max(to_down, b_block - block[i]);
			}
			
			b_block = block[i];
		}

		cout << '#' << tc << ' ';
		cout << to_up << ' ' << to_down << '\n';
	}

	return 0;
}
