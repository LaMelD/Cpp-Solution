#include <iostream>

using namespace std;

int main()
{
	int a, b, v;
	cin >> a >> b >> v;

	int climb = a - b;
	int limit = v - a;
	int k = limit / climb;
	if (limit % climb != 0)
	{
		k++;
	}

	int ans = k + 1;

	cout << ans << endl;
}
