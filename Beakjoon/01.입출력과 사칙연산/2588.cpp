#include <iostream>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	int _1 = b % 10;
	int _10 = (b % 100 - _1) / 10;
	int _100 = b / 100;
	cout << _1 * a << endl;
	cout << _10 * a << endl;
	cout << _100 * a << endl;
	cout << a * b << endl;
}
