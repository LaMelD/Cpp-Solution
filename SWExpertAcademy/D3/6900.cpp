#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		int N, M;
		cin >> N >> M;
		vector<string> N_v;
		vector<int> N_money;
		vector<string> M_v;
		for (int i = 0; i < N; i++)
		{
			string tmp;
			int money;
			cin >> tmp >> money;
			N_v.push_back(tmp);
			N_money.push_back(money);
		}
		for (int i = 0; i < M; i++)
		{
			string tmp;
			cin >> tmp;
			M_v.push_back(tmp);
		}

		bool flag;
		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				flag = true;
				for (int k = 0; k < 8; k++)
				{
					if (N_v[i][k] == '*')
						continue;

					if (N_v[i][k] != M_v[j][k])
					{
						flag = false;
						break;
					}
				}

				if (flag)
				{
					sum += N_money[i];
				}
			}
		}

		cout << '#' << tc << " ";
		cout << sum << endl;
	}

	return 0;
}
