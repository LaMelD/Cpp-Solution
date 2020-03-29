#include <iostream>
#include <vector>

using namespace std;

int main()
{
	//입출력 가속
	cin.tie(NULL);
	cout.sync_with_stdio(false);

	int n;
	cin >> n;
	double input;
	double max = 0;
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		if (input > max) max = input;
		sum += input;
	}

	sum = sum / n;
	sum = sum / max;
	sum = sum * 100;

	cout.precision(4);
	cout << sum << endl;

	return 0;
}
