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

	vector<string> s(n);

	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}

	sort(s.begin(), s.end(), [](string a, string b){
			if (a.length() == b.length())
			{
				for (int i = 0; i < a.length(); i++)
				{
					if (a[i] == b[i])
					{
						continue;
					}
					return a[i] < b[i];
				}
			}
			return a.length() < b.length();
	});

	string a = "";
	for (int i = 0; i < n; i++)
	{
		if (a == s[i])
		{
			continue;
		}
		cout << s[i] << '\n';
		a = s[i];
	}

	return 0;
}
