#include <iostream>
#include <cmath>

using namespace std;

const double PI = acos(-1.0);

int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		int x1, y1, x2, y2;
		double r1, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		double x = abs(x1 - x2);
		double y = abs(y1 - y2);
		double dist = sqrt(x * x + y * y);

		if (dist == 0)
		{
			if (r1 == r2)
			{
				cout << "-1" << endl;
			}
			else
			{
				cout << "0" << endl;
			}
		}
		else
		{
			if (dist < r1 + r2)
			{
				if (abs(r1 - r2) == dist)
				{
					cout << "1" << endl;
				}
				else if (abs(r1 - r2) < dist)
				{
					cout << "2" << endl;
				}
				else
				{
					cout << "0" << endl;
				}
			}
			else if (dist == r1 + r2)
			{
				cout << "1" << endl;
			}
			else
			{
				cout << "0" << endl;
			}
		}
	}
	return 0;
}
