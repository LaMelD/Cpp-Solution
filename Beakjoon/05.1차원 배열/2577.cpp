#include <iostream>

using namespace std;

int main()
{
	int a, b, c;
	int arr[10] = { 0, };
	cin >> a >> b >> c;
	int x = a * b * c;
	int chk;
	while (x != 0)
	{
		chk = x % 10;
		x = x / 10;
		arr[chk]++;
	}

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << "\n";
	}
}
