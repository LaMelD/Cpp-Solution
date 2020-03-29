#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int* ppl = new int[N + 1];
	ppl[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> ppl[i];
	}

	sort(ppl + 0, ppl + N + 1);

	int sum = 0;
	int* time = new int[N + 1];
	time[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		time[i] = time[i - 1] + ppl[i];
		sum += time[i];
	}

	cout << sum << '\n';

	return 0;
}
