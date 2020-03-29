#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	if (n == 1)
	{
		cout << '1' << endl;
		return 0;
	}

	n -= 1;

	int cnt = 1;
	int minus = 6;
	int stock = minus;
	while (n > 0)
	{
		n -= stock;
		stock += minus;
		cnt++;
	}

	cout << cnt << endl;

	return 0;
}
