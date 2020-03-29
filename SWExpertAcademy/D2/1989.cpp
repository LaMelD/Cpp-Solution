#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool palindrome(string s) {
	int left = 0;
	int right = s.length() - 1;

	while (1)
	{
		if (left == right || right < left)
			break;

		if (s[left] != s[right])
		{
			return false;
		}
		left++;
		right--;
	}
	return true;

}

int main()
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		string s;
		cin >> s;

		int ans = palindrome(s);

		cout << '#' << tc << ' ';
		cout << ans << endl;
	}
}
