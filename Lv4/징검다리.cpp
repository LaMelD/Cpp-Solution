#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) 
{
	int answer = 0;
	sort(rocks.begin(), rocks.end());
	rocks.push_back(distance);
	
	//각 바위 사이의 거리의 최솟값을 mid로 한다
	int max, min, mid;
	max = distance;
	min = 0;
	while (min <= max) 
	{
		mid = (min + max) / 2;
		int cur = 0;
		int hits = 0;
		for (int i = 0; i < rocks.size(); i++) 
		{
			//바위 사이의 거리가 mid보다 작다면 바위를 제거하여 hit++한다
			if (rocks[i] - cur < mid) 
			{
				hits++;
			}
			//아니라면 커서를 옮긴다
			else 
			{
				cur = rocks[i];
			}
		}

		//제거한 바위의 수가 n보다 크다면
		//바위를 제거하는 수를 줄이기 위해 mid를 줄인다
		if (hits > n) 
		{
			max = mid - 1;
		}
		//제거한 바위의 수가 n보다 작다면
		//바위를 제거하는 수를 늘리기 위해 mid를 높인다
		//제거한 바위의 수가 n과 같다면
		//오차를 줄이기위해 mid를 줄인다
		else 
		{
			min = mid + 1;
		}
	}

	answer = max;
 
	return answer;
}
