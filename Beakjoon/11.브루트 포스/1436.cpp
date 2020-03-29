#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int num = 666;

	int i = 1;
	while (i != n)
	{
		num++;

		bool flag = false;

		int tmp = num;
		int cnt_6 = 0;
		while (tmp != 0)
		{
			if (tmp % 10 == 6)
			{
				cnt_6++;
			}
			else
			{
				cnt_6 = 0;
			}

			if (cnt_6 == 3)
			{
				flag = true;
				break;
			}

			tmp /= 10;
		}

		if (flag)
		{
			i++;
		}
	}

	cout << num << endl;

	return 0;
}
