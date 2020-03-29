#include <iostream>

using namespace std;

//손으로 계산하다가 포기하고 생각대로 넣어 놓으니
//정답이였다
int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		double d, a, b, f;
		cin >> d >> a >> b >> f;

		double ans = 0;
		double time;
		while (1)
		{
			time = d / (b + f);
			ans += f * time;
			d = d - (a + b) * time;

			time = d / (a + f);
			ans += f * time;
			d = d - (a + b) * time;

			if (d < 0.00000001)
				break;
		}

		printf("#%d %.6lf\n", tc, ans);
	}

	return 0;
}
