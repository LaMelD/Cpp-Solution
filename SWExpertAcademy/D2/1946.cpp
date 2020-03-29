#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct node
{
	char ch;
	int it;
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
		vector<node> v(n);
		char a;
		int it;
		for (int i = 0; i < n; i++)
		{
			cin >> a;
			cin >> it;
			v[i].ch = a;
			v[i].it = it;
		}

		cout << '#' << tc << ' ';

		int i, j, cnt;
		i = 0; j = 0; cnt = 0;
		while (1)
		{
			if (j == 10)
			{
				j = 0;
				cout << '\n';
				continue;
			}

			if (v[i].it == cnt)
			{
				cnt = 0;
				i++;
				if (i == v.size())
				{
					break;
				}
			}

			cout << v[i].ch;

			j++;
			cnt++;
		}

		cout << '\n';
	}
}
