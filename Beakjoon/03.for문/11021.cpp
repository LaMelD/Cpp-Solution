#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	int a, b;
	for (int tc = 1; tc <= T; tc++) {
		cin >> a >> b;
		cout << "Case #" << tc << ": ";
		cout << a + b << "\n";
	}
}
