#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);
	int n, i = 1;
	int max = 0, max_idx;
	while (1)
	{
		cin >> n;
		if (cin.eof()) break;
		if (n > max)
		{
			max = n;
			max_idx = i;
		}
		i++;
	}
	cout << max << "\n" << max_idx << "\n";
}
