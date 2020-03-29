#include <iostream>
#include <string>

using namespace std;

int main()
{
	long long A, B, C;
	cin >> A >> B >> C;

	if (B >= C)
		cout << "-1" << endl;
	else
	{

		long long ans = A / (C - B) + 1;

		cout << ans << endl;
	}
}
