#include <iostream>
#include <string>

using namespace std;

int solve(int i)
{
	int cnt = 0;
	while (i != 0)
	{
		int tmp = i % 10;
		
		if (tmp == 3 || tmp == 6 || tmp == 9) cnt++;

		i = i / 10;
	}
	return cnt;
}

int main()
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);

	int n;
	cin >> n;
	string ans = "";
	for (int i = 1; i <= n; i++)
	{
		int cnt369 = solve(i);
		if (cnt369 == 0)
		{
			ans += to_string(i);
		}
		else
		{
			for (int j = 0; j < cnt369; j++)
			{
				ans += '-';
			}
		}
		ans += ' ';
	}

	ans.pop_back();
	cout << ans << endl;
}
