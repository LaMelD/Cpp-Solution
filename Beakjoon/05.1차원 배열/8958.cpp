#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	//입출력 가속
	cin.tie(NULL);
	cout.sync_with_stdio(false);

	int T;
	cin >> T;
	string s;
	for (int tc = 0; tc < T; tc++)
	{
		cin >> s;
		vector<int> score;
		if (s[0] == 'O') score.push_back(1);
		else score.push_back(0);

		int sum = score[0];

		for (int i = 1; i < s.length(); i++)
		{
			if (s[i] == 'O')
			{
				if (s[i - 1] == 'O')
				{
					score.push_back(score[i - 1] + 1);
				}
				else
				{
					score.push_back(1);
				}
			}
			else
			{
				score.push_back(0);
			}
			sum += score[i];
		}
		cout << sum << "\n";
	}

	return 0;
}
