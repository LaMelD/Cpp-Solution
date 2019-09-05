#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b)
{
	return a < b ? b : a;
}

//DFS를 사용하여 아래에서 부터 가질 수 있는 최대값을 W[i][j]에 저장한다
//visit을 사용하여 방문여부를 확인한다 -> memoization
//land	:: 원본배열 (메모리 절약, 접근속도 향상)
//i		:: 행 번호
//j		:: 열 번호
//W		:: 각각에서 얻을 수 있는 최대값
//visit	:: 방문여부 확인
int solve(vector<vector<int>>& land, int i, int j, vector<vector<int>>& W, vector<vector<bool>>& visit)
{
	int& ret = W[i][j];

	//land의 마지막 행에 도달했다면 land[i][j]값을 리턴한다
	if (i >= land.size() - 1)
	{
		ret = land[i][j];
		return ret;
	}

	//방문했는지 확인한다
	if (visit[i][j]) return ret;
	visit[i][j] = true;

	int m = 0;
	for (int k = 0; k < 4; k++)
	{
		if (k == j) continue;
		//가장 큰 값을 고른다
		m = max(m, solve(land, i + 1, k, W, visit));
	}
	//W[i][j]에 land와 m의 값을 더해서 넣는다
	ret = m + land[i][j];

	return ret;
}

int solution(vector<vector<int>> land)
{
	int ans = 0;
	vector<vector<int>> W(land.size(), vector<int>(4));
	vector<vector<bool>> visit(land.size(), vector<bool>(4));

	for (int i = 0; i < 4; i++)
	{
		//시작 포인트
		ans = max(ans, solve(land, 0, i, W, visit));
	}

	return ans;
}
