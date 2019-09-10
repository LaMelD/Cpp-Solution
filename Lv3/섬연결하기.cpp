#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//최소비용신장트리
//prim 알고리즘
int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	int maximum = 0;
	int i, j;
    
    //////////////////////////////////////////////////////////////////////////////////////
    //W 초기화 과정
    //연결되어 있다면 가중치를 넣는다
    //연결되어 있지 않다면 MAXIMUM + 1을 넣어준다
    //i == j라면 0을 넣어준다
	vector<vector<int>> W(n, vector<int>(n));

	for (i = 0; i < costs.size(); i++)
    {
	    if (maximum < costs[i][2]) maximum = costs[i][2];
    }

	maximum++;

	for (i = 0; i < n; i++)
    {
		for (j = 0; j < n; j++)
        {
			if (i == j) W[i][j] == 0;
			else W[i][j] = maximum;
		}
	}

	for (i = 0; i < costs.size(); i++)
    {
		W[costs[i][0]][costs[i][1]] = costs[i][2];
		W[costs[i][1]][costs[i][0]] = costs[i][2];
	}
    ////////////////////////////////////////////////////////////////////////////////////////

    //프림알고리즘 시작
	int vnear;
	int min;
	vector<int> distance;

    //v0 부터 시작한다
	for (i = 0; i < n - 1; i++)
    {
		distance.push_back(W[0][i+1]);
	}

	for (i = 0; i < n - 1; i++)
    {
		min = maximum;
		for (j = 0; j < n - 1; j++)
        {
			if (distance[j] >= 0 && distance[j] < min)
            {
				min = distance[j];
				vnear = j;
			}
		}
        //연결할 수 없는 섬은 주어지지 않기 때문에 min == maximum일 경우는 생각하지 않아도 된다
        answer += min;
		distance[vnear] = -1;
		for (j = 0; j < n - 1; j++)
        {
			if (W[j + 1][vnear + 1] < distance[j])
            {
				distance[j] = W[j + 1][vnear + 1];
			}
		}
	}

	return answer;
}
