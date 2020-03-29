#include <iostream>

using namespace std;

int main()
{
	int n;
	bool arr[42] = { 0, };
	int cnt = 0;
	for (int i = 0; i < 10; i++) {
		cin >> n;
		if (!arr[n % 42])
		{
			arr[n % 42] = true;
			cnt++;
		}
	}
	cout << cnt << "\n";
}
