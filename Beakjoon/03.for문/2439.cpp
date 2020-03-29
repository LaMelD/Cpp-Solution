#include <iostream>
#include <string>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);
	int n;
	cin >> n;
	string s = "";
	for (int i = 0; i < n; i++) s += " ";

	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j >= n - 1 - i; j--)
		{
			s[j] = '*';
		}
		cout << s << "\n";
	}
}
