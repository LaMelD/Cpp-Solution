#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}

void DFS(vector<vector<int>>& pic, int& m, int& n, int m_i, int n_i, vector<vector<bool>>& visit, int& color, int& max_size_of_one_area) 
{
	//m_i와 n_i가 영역 내의 있는지 확인
	if (m_i == m || m_i < 0) return;
	if (n_i == n || n_i < 0) return;

	//방문여부를 확인한다
	if (visit[m_i][n_i]) return;
	//색이 같은지 확인한다
	if (color != pic[m_i][n_i]) return;
	visit[m_i][n_i] = true;
	//영역의 사이즈++
	max_size_of_one_area++;


	//우 하 좌 상 순서로 확인한다
	DFS(pic, m, n, m_i, n_i + 1, visit, color, max_size_of_one_area);
	DFS(pic, m, n, m_i + 1, n_i, visit, color, max_size_of_one_area);
	DFS(pic, m, n, m_i, n_i - 1, visit, color, max_size_of_one_area);
	DFS(pic, m, n, m_i - 1, n_i, visit, color, max_size_of_one_area);
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	//방문여부를 확인
	vector<vector<bool>> visit(m, vector<bool>(n));
	//영역의 크기 중 가장 큰 것을 저장
	int maxi = 0;
	//현재 방문한 좌표의 색
	int color;
	//영역의 수
	int number_of_area = 0;
	//영역의 크기
	int max_size_of_one_area;

	for (int i = 0; i < m; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			//현재 좌표를 방문했는가
			if (visit[i][j]) continue;
			//영역의 크기 초기화
			max_size_of_one_area = 0;
			//현재 좌표의 색
			color = picture[i][j];
			//색이 같은 연결된 모든 좌표를 확인
			DFS(picture, m, n, i, j, visit, color, max_size_of_one_area);
			//좌표의 색이 0 이 아니라면
			if (color != 0) 
			{
				//영역의 수++, maxi를 조정해준다
				number_of_area++;
				maxi = max(max_size_of_one_area, maxi);
			}
		}
	}

	vector<int> ans(2);
	ans[0] = number_of_area;
	ans[1] = maxi;
	return ans;
}
