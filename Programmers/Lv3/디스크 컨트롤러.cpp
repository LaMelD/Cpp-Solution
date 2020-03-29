#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp
{
	bool operator()(pair<int, int> t, pair<int, int> u)
	{
		if (t.first == u.first) return t.second > u.second;
		return t.first > u.first;
	}
};

//SJF
int solution(vector<vector<int>> jobs)
{
	int answer = 0;
	int jobsize = jobs.size();
	sort(jobs.begin(), jobs.end());
	//pair.first :: 작업 소요시간, pair.second :: 작업 요청시간
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

	int index = 0;
	int time = 0;
	int i = 0;
	//종료된 작업수가 총작업 수보다 작을 때 까지 반복
	while (index < jobs.size())
	{
		//현재 시간보다 요청시간이 작은 작업을 pq에 push한다
		for (int j = i; j < jobs.size(); j++)
		{
			if (time < jobs[i][0])
			{
				break;
			}
			else
			{
				pq.push({ jobs[i][1], jobs[i][0] });
				i++;
			}
		}

		//pq가 비어있지 않다면
		if (!pq.empty())
		{
			//대기시간 + 작업시간을 answer에 더해준다
			answer += time + pq.top().first - pq.top().second;
			//시간을 보정한다
			time += pq.top().first;
			//pq의 가장 윗 값을 pop
			pq.pop();
			//작업하나를 완료했으므로 index++
			index++;
		}
		//비어있다면
		else
		{
			//시간을 ++한다
			time++;
		}
	}

	//평균 작업시간을 구한다
	answer /= jobsize;

	return answer;
}
