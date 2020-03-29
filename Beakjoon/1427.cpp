#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);

	string s;
	cin >> s;

	sort(s.begin(), s.end(), [](char a, char b) {return a > b; });

	cout << s << '\n';

	return 0;
}
