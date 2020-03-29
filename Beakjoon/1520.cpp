#include <iostream>
#include <vector>
#define INT_MAX 2147483647

using namespace std;

vector<vector<int>> W;
int M, N;

int dfs(vector<vector<int>>& visit, vector<vector<int>>& MAP, int i, int j)
{
	int& ret = W[i][j];

	if (visit[i][j])
	{
		return ret;
	}
	visit[i][j] = true;

	if (i == M && j == N)
	{
		ret = 1;
		return ret;
	}

	if (MAP[i][j] > MAP[i][j + 1])
	{
		ret += dfs(visit, MAP, i, j + 1);
	}

	if (MAP[i][j] > MAP[i + 1][j])
	{
		ret += dfs(visit, MAP, i + 1, j);
	}

	if (MAP[i][j] > MAP[i][j - 1])
	{
		ret += dfs(visit, MAP, i, j - 1);
	}

	if (MAP[i][j] > MAP[i - 1][j])
	{
		ret += dfs(visit, MAP, i - 1, j);
	}

	return ret;
}

int main()
{
	cin >> M >> N;
	vector<vector<int>> MAP(M + 2, vector<int>(N + 2, INT_MAX));
	W = vector<vector<int>>(M + 2, vector<int>(N + 2, 0));
	vector<vector<int>> visit(M + 2, vector<int>(N + 2, 0));

	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> MAP[i][j];
		}
	}

	int ans = dfs(visit, MAP, 1, 1);

	if (ans == 0)
	{
		cout << "-1" << endl;
	}
	else
	{
		cout << ans << endl;
	}

	return 0;
}
