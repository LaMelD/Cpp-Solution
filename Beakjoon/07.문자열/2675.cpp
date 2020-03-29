#include <iostream>
#include <string>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		int n;
		string s;
		cin >> n >> s;
		for (int i = 0; i < s.length(); i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << s[i];
			}
		}
		cout << endl;
	}
}
