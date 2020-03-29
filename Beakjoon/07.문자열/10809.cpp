#include <iostream>
#include <string>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);

	string s;
	cin >> s;
	int pos[26];
	for (int i = 0; i < 26; i++)
	{
		pos[i] = -1;
	}

	for (int i = 0; i < s.length(); i++)
	{
		if (pos[s[i] - 'a'] == -1)
		{
			pos[s[i] - 'a'] = i;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		cout << pos[i];
		if (i != 25)
		{
			cout << ' ';
		}
	}
}
