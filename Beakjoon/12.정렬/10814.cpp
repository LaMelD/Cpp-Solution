#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);

	int n;
	cin >> n;

	vector<pair<int, int>> arr;
	vector<string> s;
	int a;
	string b;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		arr.push_back(make_pair(a, i));
		s.push_back(b);
	}

	sort(arr.begin(), arr.end(), [](pair<int, int> a, pair<int, int> b) {
		if (a.first == b.first)
		{
			return a.second < b.second;
		}
		return a.first < b.first;
	});

	for (int i = 0; i < n; i++)
	{
		cout << arr[i].first << ' ' << s[arr[i].second] << '\n';
	}

	return 0;
}
