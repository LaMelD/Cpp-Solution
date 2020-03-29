#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node
{
	int nums;
	int jumsu;
	bool operator()(node a, node b)
	{
		if (a.nums == b.nums)
		{
			return a.jumsu < b.jumsu;
		}
		return a.nums < b.nums;
	}
};

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

		vector<int> jumsu(101, 0);
		int input;
		for (int i = 0; i < 1000; i++)
		{
			cin >> input;
			jumsu[input]++;
		}

		priority_queue<node, vector<node>, node> pq;

		node tmp;
		for (int i = 0; i <= 100; i++)
		{
			tmp.nums = jumsu[i];
			tmp.jumsu = i;
			pq.push(tmp);
		}


		cout << '#' << tc << ' ';
		cout << pq.top().jumsu << '\n';
	}

	return 0;
}
