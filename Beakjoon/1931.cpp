#include <iostream>
#include <algorithm>

using namespace std;

struct node {
	int start = 0;
	int end = 0;
};

int main()
{
	int N;
	cin >> N;
	node* meeting = new node[N];
	for (int i = 0; i < N; i++)
	{
		cin >> meeting[i].start >> meeting[i].end;
	}

	sort(meeting + 0, meeting + N, [](node a, node b) {
		if (a.end == b.end)
		{
			return a.start < b.start;
		}
		return a.end < b.end;
	});

	int cnt = 0;
	int time = 0;
	for (int i = 0; i < N; i++)
	{
		if (time <= meeting[i].start)
		{
			time = meeting[i].end;
			cnt++;
		}
	}

	cout << cnt << '\n';

	return 0;
}
