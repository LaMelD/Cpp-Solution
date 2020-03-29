#include <iostream>
#include <string>

using namespace std;

int main()
{
	int H, W, N, T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> H >> W >> N;
		int X, Y;

		if (N % H == 0)
		{
			Y = H;
			X = N / H;
		}
		else
		{
			Y = N % H;
			X = N / H + 1;
		}

		string ans = to_string(Y);
		if (X < 10)
		{
			ans += '0';
		}
		ans += to_string(X);

		cout << ans << endl;
	}
}
