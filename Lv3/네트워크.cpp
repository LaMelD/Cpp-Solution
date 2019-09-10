#include <string>
#include <vector>
#include <iostream>

using namespace std;

int ans = 0;
//memoization
vector<bool> visit;
vector<vector<int>> W;

//
//방문가능한 노드를 모두 방문한다
void DFS(int n, vector<int> v, int idx) 
{
	//현재 노드의 방문여부를 수정
	visit[idx] = true;
	v[idx] = -1;
    
	for (int i = 0; i < n; i++) 
	{
		//연결된 다음번 방문할 노드를 결정
		if (v[i] == 1) 
		{
			for (int j = 0; j < n; j++) 
			{
				//W[i][j]와 v[j]를 비교한다.
				//노드 i와 노드 j가 연결되어있는가
				if (W[i][j] == 1)
				{
					//이미 방문했던 노드라면 continue
					if (v[j] == -1) continue;

					//v배열 j번째를 수정한다
					v[j] = W[i][j];
				}
			}
			DFS(n, v, i);
			return;
		}
	}
    //네트워크의 수++
	ans++;
}

int solution(int n, vector<vector<int>> computers)
{
	int answer = 0;
	W = computers;
	//노드를 방문했는지 확인하기 위해서
	visit = vector<bool>(n);

	for (int i = 0; i < n; i++) 
	{
		//노드를 방문하지 않았다면
		if (!visit[i]) 
        {
			DFS(n, computers[i], i);
		}
	}

	cout << ans << endl;

	return ans;
}



///////////////////////////////////////////////////////////////////////////////////////////////////
//깔끔하게 정리
#include <string>
#include <vector>

using namespace std;

void dfs(int idx, vector<vector<int>>& computers, int n, vector<bool>& visit)
{
	visit[idx] = true;
	for (int i = 0; i < n; i++)
	{
		//확인하는 노드가 이전에 방문하지 않았고 현재 노드와 연결되어 있는가
		if (!visit[i] && computers[idx][i])
			dfs(i, computers, n, visit);
	}

}

int solution(int n, vector<vector<int>> computers)
{
	int answer = 0;
	vector<bool> visit(n);

	for (int i = 0; i < n; i++)
	{
		if (!visit[i])
		{
			answer++;
			dfs(i, computers, n, visit);
		}
	}
	return answer;
}
