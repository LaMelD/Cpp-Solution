#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	//입출력 가속
	cin.tie(NULL);
	cout.sync_with_stdio(false);

	vector<bool> flag(10001);
	for (int i = 1; i < 10001; i++)
	{
		if (flag[i]) continue;

		cout << i << "\n";

		string s;
		int tmp = i;
		while (1)
		{
			s = to_string(tmp);
			for (int j = 0; j < s.length(); j++)
			{
				tmp += s[j] - '0';
			}

			if (tmp > 10000) break;

			flag[tmp] = true;
		}
	}

	return 0;
}
