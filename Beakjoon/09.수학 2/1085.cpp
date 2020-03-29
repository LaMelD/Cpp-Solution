#include <iostream>
#include <cstring>

using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int a = min(x, w - x);
	int b = min(y, h - y);

	int ans = min(a, b);

	cout << ans << endl;

	return 0;
}
