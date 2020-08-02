#include <iostream>
#include <vector>
#include <string>

using namespace std;

// W : 차량의 무게
// R : 단위 무게당 요금
// m : 차량의 대수
// n : 주차 공간
int solve(int n, int m, vector<int> R, vector<int> W, vector<int> order)
{
	int res = 0;
	vector<int> state(n, 0);
	bool isfull = false;
	for (int i = 0; i < order.size(); i++)
	{
		// 차량이 나가는 경우
		if (order[i] < 0)
		{
			order[i] *= -1;
			for (int j = 0; j < n; j++)
			{
				if (state[j] == order[i])
				{
					state[j] = 0;
					break;
				}
			}
			isfull = false;
		}
		// 차량이 들어오는 경우
		else
		{
			// 주차 공간이 모두 차있는 경우
			if (isfull)
			{
				int out = NULL;
				for (int j = i + 1; j < order.size(); j++)
				{
					if (order[j] < 0)
					{
						out = order[j] * -1;
						order.erase(order.begin() + j);
						break;
					}
				}
				for (int j = 0; j < n; j++)
				{
					if (state[j] == out)
					{
						state[j] = order[i];
						res += W[order[i] - 1] * R[j];
						break;
					}
				}
			}
			// 주차 공간이 남아 있는 경우
			else
			{
				for (int j = 0; j < n; j++)
				{
					if (state[j] == 0)
					{
						state[j] = order[i];
						res += W[order[i] - 1] * R[j];
						break;
					}
				}
				isfull = true;

				for (int j = 0; j < n; j++)
				{
					if (state[j] == 0)
					{
						isfull = false;
						break;
					}
				}
			}
		}
	}
	return res;
}

int main()
{
	int TC;
	cin >> TC;

	for (int tc = 1; tc <= TC; tc++)
	{
		int n, m;
		cin >> n >> m;
		vector<int> R(n, 0), W(m, 0), order(2 * m, 0);

		for (int i = 0; i < n; i++)
		{
			cin >> R[i];
		}
		for (int i = 0; i < m; i++)
		{
			cin >> W[i];
		}
		for (int i = 0; i < 2 * m; i++)
		{
			cin >> order[i];
		}

		int result = solve(n, m, R, W, order);

		cout << '#' << tc << ' ' << result << '\n';
	}
}