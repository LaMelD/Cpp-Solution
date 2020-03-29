#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);
	int a, b;
	while (1)
	{
		cin >> a >> b;
		if (cin.eof())
			break;
		cout << a + b << "\n";
	}
}
