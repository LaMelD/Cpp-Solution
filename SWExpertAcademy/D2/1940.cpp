#include <iostream>
#include <string>.
#include <vector>

using namespace std;

struct node
{
	int flag;
	int accel;
};

int main()
{
	int  T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		int n;
		cin >> n;
		vector<node> command;

		node input;
		for (int i = 0; i < n; i++)
		{
			cin >> input.flag;
			if (input.flag != 0)
			{
				cin >> input.accel;
			}
			else
			{
				input.accel = 0;
			}

			command.push_back(input);
		}

		int v = 0;
		int s = 0;
		for (int i = 0; i < n; i++)
		{
			switch (command[i].flag)
			{
			case 0 :
			case 1 :
				v = v + command[i].accel;
				s = s + v;
				break;
			case 2 :
				if (v < command[i].accel)
				{
					v = 0;
				}
				else
				{
					v = v - command[i].accel;
				}
				s = s + v;
				break;
			}
		}

		cout << '#' << tc << ' ';
		cout << s << '\n';
	}

	return 0;
}
