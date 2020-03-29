#include <iostream>

using namespace std;

int CountNum(int n)
{

	int pos[3] = { 0 };
	int cnt = 0;

	if (n < 100)
		cnt = n;
	else
	{
		cnt = 99;

		for (int i = 100; i <= n; i++)
		{
			if (i == 1000)
				return cnt;

			pos[0] = i / 100;
			pos[1] = (i - pos[0] * 100) / 10;
			pos[2] = i % 10;

			if ((pos[0] - pos[1]) == (pos[1] - pos[2]))
			{
				cnt++;
			}
		}
	}

	return cnt;
}

int main()
{
	int n;
	int result = 0;
	cin >> n;

	result = CountNum(n);

	cout << result << endl;
	
	return 0;
}
