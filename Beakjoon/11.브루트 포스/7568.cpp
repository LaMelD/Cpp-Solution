#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int people[51][2];

	for (int i = 0; i < n; i++)
	{
		cin >> people[i][0] >> people[i][1];
	}

	int ans[51] = { 0, };
	for (int i = 0; i < n; i++)
	{
		int rank = n;
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				continue;
			}

			if (people[i][0] < people[j][0] && people[i][1] < people[j][1])
			{
				continue;
			}

			rank--;
		}
		ans[i] = rank;
	}
	cout << ans[0];
	for (int i = 1; i < n; i++)
	{
		cout << ' ' << ans[i];
	}
}
