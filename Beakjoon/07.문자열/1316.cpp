#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	int ans = 0;
	cin >> n;
	for (int tc = 0; tc < n; tc++)
	{
		string s;
		bool is_group = true;
		cin >> s;
		string tmp = "";
		char chk = s[0];
		for (int i = 1; i < s.length(); i++)
		{
			if (s[i] == chk)
			{
				continue;
			}
			else
			{
				tmp += chk;
				chk = s[i];
				bool flag = false;
				for (int j = 0; j < tmp.length(); j++)
				{
					if (tmp[j] == chk)
					{
						flag = true;
						break;
					}
				}

				if (flag)
				{
					is_group = false;
					break;
				}
			}
		}
		if (is_group)
		{
			ans++;
		}
	}

	cout << ans << endl;
}
