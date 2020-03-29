#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b)
{
	return a < b ? b : a;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> card(n);

	for (int i = 0; i < n; i++)
	{
		cin >> card[i];
	}
	
	int sum = 0;
	int ans = 0;
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		sum += card[i];
		for (int j = i + 1; j < n; j++)
		{
			sum += card[j];
			for (int k = j + 1; k < n; k++)
			{
				sum += card[k];

				if (sum == m)
				{
					flag = true;
					ans = sum;
					break;
				}
				else if (sum < m)
				{
					ans = max(ans, sum);
				}

				sum -= card[k];
			}
			if (flag) break;

			sum -= card[j];
		}
		if (flag) break;

		sum -= card[i];
	}

	cout << ans << endl;

	return 0;
}
