#include <iostream>

using namespace std;

//규칙 찾기
int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int a, b, n;
		cin >> a >> b;
		n = b - a;

		long long cnt = 1;
		long long ans = 1;
		long long tmp;
		while (1)
		{
			tmp = cnt * cnt;
			if (n <= tmp)
			{
				break;
			}
			ans++;

			tmp += cnt;
			if (n <= tmp)
			{
				break;
			}
			ans++;

			cnt++;
		}

		cout << ans << endl;
	}

	return 0;
}
