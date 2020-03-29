#include <iostream>
#include <vector>

using namespace std;

vector<long long> getres(int target)
{
	vector<long long> ret;

	long long a = 1, b = 1;
	long long tmp;
	int cnt = 0;

	while (cnt != target)
	{
		tmp = b;
		b = a;
		a = b + tmp;

		cnt++;
	}

	ret = { a, b };

	return ret;
}

int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		int k;
		cin >> k;
		vector<long long> result = getres(k);

		cout << '#' << tc << ' ';
		cout << result[0] << ' ' << result[1] << '\n';
	}
}
