#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//1에서 가장 멀리 떨어진 노드를 구한다
int solution(int n, vector<vector<int>> edge)
{
	vector<vector<bool>> W(n + 1, vector<bool>(n + 1, false));

	for (int i = 0; i < edge.size(); i++)
	{
		W[edge[i][0]][edge[i][1]] = 1;
		W[edge[i][1]][edge[i][0]] = 1;
	}

	int cur = 1;
	int far = 1;
	queue<int> q;
	vector<int> dist(n + 1, 0);
	vector<bool> visit(n + 1, false);

	//1번 노드부터 시작
	q.push(1);

	while (!q.empty()) {
		int q_size = q.size();

		//queue에 들어있던 갯수 만큼 반복
		//안쪽에서 추가된것들은 판단에 영향을 미치지 않도록 한다
		for (int k = 0; k < q_size; k++)
		{
			//1번부터 시작이기에 2번 노드부터 마지막 노드까지 확인한다
			for (int i = 2; i <= n; i++)
			{
				//노드가 연결이 되어있고 방문하지 않았다면
				if (W[q.front()][i] && !visit[i])
				{
					//1번 노드와의 거리를 저장하고
					//방문여부를 수정하고
					//queue에 넣어준다
					dist[i] = far;
					visit[i] = true;
					q.push(i);
				}
			}
			//현재 노드와 연결된 모든 노드를 확인하고 pop한다
			q.pop();
		}
		//사이클을 돌 때 마다 거리를 1증가시킨다
		far++;
	}

	//최대 거리는 far - 2가 된다
	int m = far - 2, answer = 0;

	//dist가 far - 2인 곳의 갯수를 구한다
	for (int i = 2; i <= n; i++)
	{
		if (m == dist[i]) answer++;
	}

	return answer;
}
