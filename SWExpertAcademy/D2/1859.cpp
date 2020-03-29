#include <iostream>
#include <vector>

using namespace std;

//맨 뒤에서부터 확인한다
long long solve(int n, vector<int> price)
{
	long long benefit = 0;
	int max_price = price[n - 1];

	for (int i = n - 2; i >= 0; i--)
	{
		if (price[i] < max_price)
		{
			benefit += (long long)(max_price - price[i]);
		}
		else
		{
			max_price = price[i];
		}
	}
	
	return benefit;
}

int main()
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		int n;
		cin >> n;

		int input;
		vector<int> price;

		for (int i = 0; i < n; i++)
		{
			cin >> input;
			price.push_back(input);
		}

		long long ans = solve(n, price);

		cout << '#' << tc;
		cout << ' ' << ans << endl;
	}
}
