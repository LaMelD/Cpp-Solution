#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		vector<int> v;
		for (int i = 0; i < 10; i++)
		{
			int input;
			cin >> input;
			v.push_back(input);
		}

		sort(v.begin(), v.end());
		v.pop_back();
		v.erase(v.begin());

		double ans = 0;
		for (int i = 0; i < 8; i++)
		{
			ans += (double)v[i];
		}
		ans = ans / 8;

		cout << '#' << tc << ' ';
		printf("%.0lf\n", ans);
	}
}
