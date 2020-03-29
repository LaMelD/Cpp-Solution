#include <vector>

using namespace std;

const int MOD = 20170805;

//위쪽을 체크한다
int chk_upside(vector<vector<int>>& city_map, vector<vector<int>>& W, int i, int j) 
{
	
	if (i == 0) return 0;

	//위쪽이 우회전 좌회전 금지 구간이라면
	if (city_map[i - 1][j] == 2) 
	{
		//다시 윗쪽을 확인한다
		return chk_upside(city_map, W, i - 1, j);
	}

	return W[i - 1][j];
}

//왼쪽을 체크한다
int chk_leftside(vector<vector<int>>& city_map, vector<vector<int>>& W, int i, int j) 
{
	if (j == 0) return 0;

	//왼쪽이 우회전 좌회전 금지 구간이라면
	if (city_map[i][j - 1] == 2) 
	{
		//다시 왼쪽을 확인한다
		return chk_leftside(city_map, W, i, j - 1);
	}

	return W[i][j - 1];
}

int solution(int m, int n, vector<vector<int>> city_map) 
{
	vector<vector<int>> W(m, vector<int>(n , 0));
	int i, j, k;
	//초기화
	for (j = 1; j < n; j++) 
	{
		//차량 통행금지를 만나면 break
		if (city_map[0][j] == 1) break;
		W[0][j] = 1;
	}

	for (i = 1; i < m; i++) 
	{
		//차량 통행금지를 만나면 break;
		if (city_map[i][0] == 1) break;
		W[i][0] = 1;
	}

	int upside;
	int leftside;
	for (i = 1; i < m; i++) 
	{
		for (j = 1; j < n; j++) 
		{
			if (city_map[i][j] == 1) continue;

			upside = chk_upside(city_map, W, i, j);
			leftside = chk_leftside(city_map, W, i, j);
			W[i][j] = (upside + leftside) % MOD;
		}
	}

	return W[m - 1][n - 1];
}
