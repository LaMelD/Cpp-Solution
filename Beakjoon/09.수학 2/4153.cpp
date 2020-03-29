#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	while (1)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 0 && b == 0 && c == 0) break;

		int big, s1, s2;

		big = a < b ? b : a;
		big = big < c ? c : big;

		if (big == a)
		{
			s1 = b;
			s2 = c;
		}
		else if (big == b)
		{
			s1 = a;
			s2 = c;
		}
		else
		{
			s1 = a;
			s2 = b;
		}

		if (big * big == s1 * s1 + s2 * s2)
		{
			cout << "right" << endl;
		}
		else
		{
			cout << "wrong" << endl;
		}
	}

	return 0;
}
