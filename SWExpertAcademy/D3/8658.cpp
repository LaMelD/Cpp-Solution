#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int solve(int n)
{
	int ret = 0;

	while (n != 0)
	{
		ret += n % 10;
		n = n / 10;
	}

	return ret;
}

int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		vector<int> sum;
		
		int input;
		for (int i = 0; i < 10; i++)
		{
			cin >> input;
			sum.push_back(solve(input));
		}

		sort(sum.begin(), sum.end());

		cout << '#' << tc << ' ';
		cout << sum.back()<< ' ' << sum.front() << endl;
	}


	return 0;
}
