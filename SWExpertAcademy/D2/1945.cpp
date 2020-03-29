#include <iostream>
#include <string>.
#include <vector>

using namespace std;

int gettopnum(int& n, int piget)
{
	int ret = 0;

	while (1)
	{
		int tmp = n % piget;
		if (tmp != 0)
		{
			break;
		}

		ret++;
		n = n / piget;
	}

	return ret;
}

int main()
{
	int  T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		int num;
		cin >> num;
		vector<int> piget = { 2, 3, 5, 7, 11 };
		vector<int> result;

		for (int i = 0; i < piget.size(); i++)
		{
			result.push_back(gettopnum(num, piget[i]));
		}

		cout << '#' << tc;
		for (int i = 0; i < piget.size(); i++)
		{
			cout << ' ' << result[i];
		}
		cout << '\n';
	}

	return 0;
}
