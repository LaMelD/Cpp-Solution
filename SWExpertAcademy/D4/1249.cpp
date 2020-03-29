//다익스트라로 풀었다
#include <iostream>
#include <vector>
#include <queue>
#define INT_MAX 2147483647

using namespace std;

//먼저 하나의 경로를 완성하기위해서
struct cmp {
	//a[0] 즉 dist값이 큰 순서대로 pq에 정렬하고
	//dist값이 같다면 x, y좌표를 오름차순으로 정렬한다
	bool operator()(vector<int> a, vector<int> b)
	{
		if (a[0] == b[0])
		{
			if (a[1] == b[1])
			{
				return a[2] < b[2];
			}
			return a[1] < b[1];
		}
		return a[0] > b[0];
	}
};

int main()
{
	int T;
	cin >> T;

	//이동 방향
	//0부터 3까지 각각 동, 서, 남, 북
	int dx[4] = { 0, 0, 1, -1 };
	int dy[4] = { 1, -1, 0, 0 };

	for (int tc = 1; tc <= T; tc++)
	{
		int n; 
		cin >> n;

		//map을 입력받아 초기화 하고
		//dist는 초기값을 INT_MAX로 한다
		vector<vector<int>> map(n, vector<int>(n, 0));
		vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				char input;
				cin >> input;
				map[i][j] = input - '0';
			}
		}

		//pq를 생성
		priority_queue<vector<int>, vector<vector<int>>, cmp> pq;

		//pq초기값 설정(시작지점)
		dist[0][0] = 0;
		pq.push({ 0, 0, 0 });
		//더 이상 확인할 위치가 없을 때까지
		while (!pq.empty())
		{
			//cost와 x, y를 받고 현재 받아온 값을 pop한다
			int cost = pq.top()[0];
			int x = pq.top()[1];
			int y = pq.top()[2];
			pq.pop();

			//현재 위치에 도달한 cost가 이미 있던
			//dist값보다 크다면 실행하지 않는다
			if (cost > dist[x][y])
			{
				continue;
			}

			//동서남북을 체크한다
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				//맵 밖으로 나갔다면 실행하지 않는다
				if (0 <= nx && nx < n && 0 <= ny && ny < n)
				{
					//이미 있던 dist값보다 설정하려는 값이 작다면 실행한다
					if (dist[nx][ny] > cost + map[nx][ny])
					{
						//dist를 갱신
						dist[nx][ny] = cost + map[nx][ny];
						//이동 가능한 지점을 pq에 push한다
						pq.push({ dist[nx][ny], nx, ny });
					}
				}
			}
		}

		cout << '#' << tc << ' ';
		cout << dist[n - 1][n - 1] << '\n';
	}

	return 0;
}
