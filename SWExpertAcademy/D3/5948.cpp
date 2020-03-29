#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> make_sum(int* arr)
{
	int idx = 0;
	vector<int> ret(35);
	for (int i = 0; i < 7; i++)
	{
		for (int j = i + 1; j < 7; j++)
		{
			for (int k = j + 1; k < 7; k++)
			{
				ret[idx++] = arr[i] + arr[j] + arr[k];
			}
		}
	}

	return ret;
}

int main()
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);

	int T;
	cin >> T;

	int* num = new int[7];

	for (int tc = 1; tc <= T; tc++)
	{
		for (int i = 0; i < 7; i++)
		{
			cin >> num[i];
		}

		vector<int> sum = make_sum(num);
		
		
		sort(sum.begin(), sum.end(), [](int a, int b) { return b < a; });
		sum.erase(unique(sum.begin(), sum.end()), sum.end());

		int ans = sum[4];

		cout << '#' << tc << ' ';
		cout << ans << endl;
	}
}
