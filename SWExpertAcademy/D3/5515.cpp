#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		int M, D;
		cin >> M >> D;

		int A[7] = { 3, 4, 5, 6, 0, 1, 2 };

		switch (M)
		{
		case 12:
			D += 30;
		case 11:
			D += 31;
		case 10:
			D += 30;
		case 9:
			D += 31;
		case 8:
			D += 31;
		case 7:
			D += 30;
		case 6:
			D += 31;
		case 5:
			D += 30;
		case 4:
			D += 31;
		case 3:
			D += 29;
		case 2:
			D += 31;
		}

		cout << '#' << tc << ' ';
		cout << A[D % 7] << '\n';
	}

	return 0;
}
