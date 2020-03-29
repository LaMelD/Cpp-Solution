#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);

	int n;
	cin >> n;

	int arr[10001] = { 0, };
	int input;

	for (int i = 0; i < n; i++)
	{
		cin >> input;
		arr[input]++;
	}

	for (int i = 0; i < 10001; i++)
	{
		if (arr[i] != 0)
		{
			for (int j = 0; j < arr[i]; j++)
			{
				cout << i << '\n';
			}
		}
	}

	return 0;
}
