#include <iostream>
#include <vector>

using namespace std;

vector<int> visit_list;

void solve(vector<vector<int>>& W, vector<bool>& visit, int& k, int idx, int far)
{
	if (visit[idx]) return;
	visit[idx] = true;

	if (far <= k)
	{
		bool flag = true;
		for (int i = 0; i < visit_list.size(); i++)
		{
			if (visit_list[i] == idx)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			visit_list.push_back(idx);
		}
	}
	else
	{
		visit[idx] = false;
		return;
	}

	for (int i = 1; i < W.size(); i++)
	{
		if (W[idx][i] != 0)
		{
			solve(W, visit, k, i, far + W[idx][i]);
		}
	}

	visit[idx] = false;
}

int solution(int N, vector<vector<int>> road, int K) {
	int ans = 0;
	visit_list.clear();
	vector<vector<int>> W(N + 1, vector<int>(N + 1));
	vector<bool> visit(N + 1);
	for (int i = 0; i < road.size(); i++) {
		if (W[road[i][0]][road[i][1]] == 0)
		{
			W[road[i][0]][road[i][1]] = road[i][2];
			W[road[i][1]][road[i][0]] = road[i][2];
		}
		else
		{
			if (W[road[i][0]][road[i][1]] > road[i][2])
			{
				W[road[i][0]][road[i][1]] = road[i][2];
				W[road[i][1]][road[i][0]] = road[i][2];
			}
		}
	}

	solve(W, visit, K, 1, 0);

	return ans = visit_list.size();
}
