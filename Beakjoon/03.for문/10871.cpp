#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);
	int n, x;
	cin >> n >> x;
	int a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (a < x) cout << a << " ";
	}
}
