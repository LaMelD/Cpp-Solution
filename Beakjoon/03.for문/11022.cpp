#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);
	int T;
	cin >> T;
	int a, b;
	for (int tc = 1; tc <= T; tc++) {
		cin >> a >> b;
		cout << "Case #" << tc << ": " << a << " + " << b << " = ";
		cout << a + b << "\n";
	}
}
