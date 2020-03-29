#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);
	int n;
	cin >> n;
	int a;
	int max = -1000001;
	int min = 1000001;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		max = max < a ? a : max;
		min = min < a ? min : a;
	}
	cout << min << " " << max << "\n";
}
