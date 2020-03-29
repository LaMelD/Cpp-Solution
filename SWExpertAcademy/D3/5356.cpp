#include <iostream>
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
		string A[5];
		int maximum = 0;
		for (int i = 0; i < 5; i++)
		{
			cin >> A[i];
			maximum = max(maximum, A[i].size());
		}
		
		cout << '#' << tc << ' ';
		for (int i = 0; i < maximum; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (A[j].size() > i)
				{
					cout << A[j][i];
				}
			}
		}
		cout << '\n';
	}

	return 0;
}
