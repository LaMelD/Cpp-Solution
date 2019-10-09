#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool can_move(int n, int m, int x, int y)
{
	if (0 <= x && x < n && 0 <= y && y < m)
	{
		return true;
	}
	return false;
}

//여기서 사용한게 BFS인지 다익스트라인지 모르겠다....
//노드에 값을 매겨서 실행했기 때문에 다익스트라인가...
int solution(vector<vector<int>> maps)
{
	int n, m;
	n = maps.size();
	m = maps[0].size();

	vector<vector<bool>> visit(n, vector<bool>(m, 0));
	queue<vector<int>> q;
	q.push({ 0, 0, 1 });

	int x, y, cnt;
	while (!q.empty())
	{
		x = q.front()[0];
		y = q.front()[1];
		cnt = q.front()[2];
		q.pop();
		if (visit[x][y])
		{
			continue;
		}
		visit[x][y] = true;

		if (x == (n - 1) && y == (m - 1))
		{
			break;
		}

		if (can_move(n, m, x, y + 1) && maps[x][y + 1] == 1 && !visit[x][y + 1])
		{
			q.push({ x, y + 1, cnt + 1 });
		}

		if (can_move(n,m,x + 1,y) && maps[x + 1][y] == 1 && !visit[x + 1][y])
		{
			q.push({ x + 1, y, cnt + 1 });
		}

		if (can_move(n, m, x - 1, y) && maps[x - 1][y] == 1 && !visit[x - 1][y])
		{
			q.push({ x - 1, y, cnt + 1 });
		}

		if (can_move(n, m, x, y - 1) && maps[x][y - 1] == 1 && !visit[x][y -1])
		{
			q.push({ x, y - 1, cnt + 1 });
		}
	}

	int ret = -1;

	if (x == (n - 1) && y == (m - 1))
	{
		ret = cnt;
	}

	return ret;
}
