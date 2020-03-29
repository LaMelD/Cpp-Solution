#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);
	int a, b;
	cin >> a >> b;
	while (a != 0 && b != 0)
	{
		cout << a + b << "\n";
		cin >> a >> b;
	}
}
