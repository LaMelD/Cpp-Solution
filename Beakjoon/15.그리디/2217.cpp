#include <iostream>
#include <algorithm>

using namespace std;

int max(int a, int b)
{
	return a < b ? b : a;
}

int main()
{
	int N;
	cin >> N;

	int k = N;
	int* rope = new int[N];
	int maximum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> rope[i];
	}

	sort(rope + 0, rope + N);

	for (int i = 0; i < N; i++)
	{
		maximum = max(maximum, rope[i] * k);
		k--;
	}

	cout << maximum << '\n';

	return 0;
}
