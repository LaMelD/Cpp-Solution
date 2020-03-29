#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main()
{
	int T;
	cin >> T;
	int n;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> n;
		priority_queue<int, vector<int>, greater<int>> pq;
		int input;
		for (int i = 0; i < n; i++)
		{
			cin >> input;
			pq.push(input);
		}
		cout << '#' << tc;
		while (!pq.empty())
		{
			cout << ' ' << pq.top();
			pq.pop();
		}
		cout << endl;
	}

	return 0;
}
