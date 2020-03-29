#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	int T, s1, s2, m1, m2;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> s1 >> m1 >> s2 >> m2;

		int s = s1 + s2;
		int m = m1 + m2;

		if (m >= 60)
		{
			s++;
			m -= 60;
		}

		if (s > 12)
		{
			s -= 12;
		}

		cout << '#' << tc << ' ';
		cout << s << ' ' << m << endl;
	}

	return 0;
}
