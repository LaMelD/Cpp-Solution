#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	int coin[11];
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> coin[i];
	}

	for (int i = N - 1; i >= 0; i--)
	{
		ans += K / coin[i];
		K = K % coin[i];
	}

	cout << ans << '\n';

	return 0;
}
