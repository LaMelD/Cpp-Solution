#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		string s;
		vector<bool> dir;
		cin >> s;

		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == 'w')
			{
				//서쪽
				dir.push_back(0);
				i += 3;
			}
			else
			{
				//북쪽
				dir.push_back(1);
				i += 4;
			}
		}

		int sum;

		if (dir.back())
		{
			sum = 0;
		}
		else
		{
			sum = 90;
		}

		dir.pop_back();

		int div = 1;
		while (!dir.empty())
		{
			div *= 2;
			if (dir.back())
			{
				sum = sum * 2;
				sum -= 90;
			}
			else
			{
				sum = sum * 2;
				sum += 90;
			}

			dir.pop_back();
		}

		while (sum % 2 == 0 && div % 2 == 0)
		{
			sum = sum / 2;
			div = div / 2;
		}

		cout << '#' << tc << ' ';
		if (div != 1)
		{
			cout << sum << '/' << div << endl;
		}
		else
		{
			cout << sum << endl;
		}
	}

	return 0;
}
