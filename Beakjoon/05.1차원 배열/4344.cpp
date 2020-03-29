#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int T;
	cin >> T;
	int n;
	for (int tc = 0; tc < T; tc++)
	{
		cin >> n;
		double input;
		vector<double> score;
		double avg = 0;

		for (int i = 0; i < n; i++)
		{
			cin >> input;
			score.push_back(input);
			avg += (double)input;
		}

		avg = avg / n;
		int cnt = 0;

		for (int i = 0; i < n; i++)
		{
			if (score[i] > avg)
			{
				cnt++;
			}
		}

		double over = (double)cnt / (double)n * 100;

		printf("%.3lf%%\n", over);
	}

	return 0;
}
