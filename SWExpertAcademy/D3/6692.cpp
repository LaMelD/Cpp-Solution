#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		int n;
		cin >> n;
		double p, x;
		double result = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> p >> x;
			result += p * x;
		}

		printf("#%d ", tc);
		printf("%.6lf\n", result);
	}

	return 0;
}
