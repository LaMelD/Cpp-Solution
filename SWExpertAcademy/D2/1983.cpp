#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct node {
	double score;
	int sid;
	bool operator()(node a, node b)
	{
		return a.score > b.score;
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
		int n, k, i;
		double a, b, c;
		cin >> n >> k;
		vector<node> student;
		node s;
		for (i = 1; i <= n; i++)
		{
			cin >> a >> b >> c;
			a = (a / 100) * 35;
			b = (b / 100) * 45;
			c = (c / 10) * 2;
			s.score = a + b + c;
			s.sid = i;
			student.push_back(s);
		}

		sort(student.begin(), student.end(), node());
		for (i = 0; i < n; i++)
		{
			if (k == student[i].sid)
			{
				break;
			}
		}
		int ans = i / (n / 10);

		cout << '#' << tc << ' ';
		switch (ans)
		{
		case 0:
			cout << "A+" << endl;
			break;
		case 1:
			cout << "A0" << endl;
			break;
		case 2:
			cout << "A-" << endl;
			break;
		case 3:
			cout << "B+" << endl;
			break;
		case 4:
			cout << "B0" << endl;
			break;
		case 5:
			cout << "B-" << endl;
			break;
		case 6:
			cout << "C+" << endl;
			break;
		case 7:
			cout << "C0" << endl;
			break;
		case 8:
			cout << "C-" << endl;
			break;
		case 9:
			cout << "D0" << endl;
			break;
		}
	}
}
