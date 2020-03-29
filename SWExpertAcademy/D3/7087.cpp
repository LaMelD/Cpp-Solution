#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		int n;
		cin >> n;
		vector<char> str;
		for (int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			str.push_back(s[0]);
		}

		sort(str.begin(), str.end());
		str.erase(unique(str.begin(), str.end()), str.end());
		char cmp = 'A';
		int i;
		for (i = 0; i < str.size(); i++)
		{
			if (cmp != str[i]) 
			{
				break;
			}
			cmp++;
		}

		cout << '#' << tc << " ";
		cout << i << '\n';
	}
	return 0;
}
