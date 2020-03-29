#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int _5kg = 0;
	int _3kg = 0;
	bool flag = true;

	while (1)
	{
		if (n % 5 == 0)
		{
			_5kg = n / 5;
			break;
		}
		else if (n % 5 == 3)
		{
			_5kg = n / 5;
			_3kg++;
			break;
		}
		else
		{
			n -= 3;
			_3kg++;
		}
	}

	if (n < 0)
	{
		cout << "-1" << endl;
	}
	else
	{
		cout << _5kg + _3kg << endl;
	}

	return 0;
}
