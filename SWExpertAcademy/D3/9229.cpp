# include <iostream>
# include <string>
# include <vector>
# include <map>
# include <algorithm>

using namespace std;

int solve(int N, int M, vector<int> weight)
{
	int ret = -1;
	for (int i = 0; i < weight.size(); i++)
	{
		for (int j = 0; j < weight.size(); j++)
		{
			if (i == j)
			{
				continue;
			}

			if (weight[i] + weight[j] <= M)
			{
				ret = ret < weight[i] + weight[j] ? weight[i] + weight[j] : ret;
			}
		}
	}
	return ret;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, M;
		vector<int> weights;
		cin >> N >> M;
		for (int i = 0; i < N; i++)
		{
			int input;
			cin >> input;
			weights.push_back(input);
		}
		int ans = solve(N, M, weights);
		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;
}