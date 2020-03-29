#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		string s;
		cin >> n;
		cin >> s;
		int sum = 0;
		for (int i = 0; i < s.length(); i++)
		{
			sum += (s[i] - '0');
		}
		cout << '#' << test_case << " ";
		cout << sum % (n - 1) << '\n';
	}
	return 0;
}
