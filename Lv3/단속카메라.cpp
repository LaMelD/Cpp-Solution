#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes)
{
	int answer = 1;

	//각각 routes의 왼쪽이 가장 작은 값으로 sort
	for (int i = 0; i < routes.size(); i++)
	{
		sort(routes[i].begin(), routes[i].end());
	}

	//진입지점을 기준으로 소트
	sort(routes.begin(), routes.end(), [](vector<int> a, vector<int> b) {return a[0] < b[0]; });

	int max = routes[0][1];
	for (int i = 1; i < routes.size(); i++)
	{
		//확인할 routes의 진입지점이 max보다 크다면
		if (max < routes[i][0])
		{
			//answer를 ++하고 max와 min을 갱신한다
			answer++;
			max = routes[i][1];
		}
		//아닌경우
		else
		{
			//확인할 routes의 탈출지점이 max보다 작거나 같다면
			if (max >= routes[i][1])
			{
				//max를 rutes의 탈출지점으로 갱신
				max = routes[i][1];
			}
		}
	}

	return answer;
}
