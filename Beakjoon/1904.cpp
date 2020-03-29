#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;

	long long a = 1, b = 2;
	if (n == 1)
	{
		cout << '1' << endl;
		return 0;
	}
	if (n == 2)
	{
		cout << '2' << endl;
		return 0;
	}

	long long ans = 0;
	for (int i = 0; i < n - 2; i++)
	{
		ans = (a + b) % 15746;
		a = b;
		b = ans;
	}

	cout << ans << endl;

	return 0;
}
