#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k)
{
	int answer = 0;
	int len = dates.size();
	priority_queue<int> pq;

	int sup_date_idx = 0;
	for (int day = 0; day < k; day++)
	{
		//push할 수 있는 dates, supplies의 값이 있고(&&) 공급받을 수 있는 날짜에 도달하면
		if (sup_date_idx < dates.size() && day == dates[sup_date_idx])
		{
			//pq에 supplies 값을 넣어준다
			pq.push(supplies[sup_date_idx++]);
		}

		//stock이 0이되면 가장 많이 공급받을 수 있는 날짜의
		//공급량을 stock에 추가한다
		if (stock == 0)
		{
			answer++;
			stock += pq.top();
			pq.pop();
		}

		//날짜가 지남에 따라 stock의 양을 1줄인다
		stock--;
	}
	return answer;
}
