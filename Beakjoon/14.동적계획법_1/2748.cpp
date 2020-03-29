#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;

	long long a = 0, b = 1;
	if (n == 0)
	{
		cout << '0' << endl;
		return 0;
	}
	if (n == 1)
	{
		cout << '1' << endl;
		return 0;
	}

	long long ans = 0;
	for (int i = 0; i < n - 1; i++)
	{
		ans = a + b;
		a = b;
		b = ans;
	}

	cout << ans << endl;

	return 0;
}
