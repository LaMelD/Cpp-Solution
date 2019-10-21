#include <string>
#include <vector>
#include <queue>

using namespace std;

//내림차순
struct DESC
{
	bool operator()(int t, int u)
	{
		return t < u;
	}
};

//오름차순
struct ASC
{
	bool operator()(int t, int u)
	{
		return t > u;
	}
};

vector<int> solution(vector<string> operations)
{
	vector<int> answer;

	priority_queue<int, vector<int>, DESC> max_pq;
	priority_queue<int, vector<int>, ASC> min_pq;

	//false라면 max_pq를 사용하고 있다
	//true라면 min_pq를 사용하고 있다
	bool state = false;
	int tmp;

	for (int i = 0; i < operations.size(); i++)
	{
		//I라면 pq에 넣어준다
		if (operations[i][0] == 'I')
		{
			string data = "";

			for (int j = 2; j < operations[i].length(); j++)
			{
				data += operations[i][j];
			}

			//현재 어떤 pq를 사용하고 있는지 판단하여
			//사용중인 pq에 넣어준다
			if (state)
				min_pq.push(stoi(data));
			else
				max_pq.push(stoi(data));
		}
		else if (operations[i][2] == '-')
		{
			//최솟값을 지워야하는데
			//현재 사용 pq가 max_pq라면 min_pq로 바꿔준다
			if (!state)
			{
				state = !state;

				while (!max_pq.empty())
				{
					min_pq.push(max_pq.top());
					max_pq.pop();
				}
			}

			//pq가 비어있지 않다면 pop한다
			//비어있으면 무시
			if (!min_pq.empty()) min_pq.pop();
		}
		else
		{
			//최댓값을 지워야하는데
			//현재 사용 pq가 min_pq라면 max_pq로 바꿔준다
			if (state)
			{
				state = !state;
				while (!min_pq.empty())
				{
					max_pq.push(min_pq.top());
					min_pq.pop();
				}
			}

			//pq가 비어있지 않다면 pop한다
			//비어있으면 무시
			if (!max_pq.empty()) max_pq.pop();
		}
	}

	//둘다 비어있다면 {0, 0}을 리턴
	if (max_pq.size() == 0 && min_pq.size() == 0)
	{
		return { 0, 0 };
	}

	//마지막으로 사용한 pq가 어떤 것인지 판단하여 
	//max와 min값을 받아온다
	int max, min;
	if (state)
	{
		min = min_pq.top();
		//empty()를 이용하면 값을 계속 복제해야 하므로 시간이 좀 더 걸린다
		while (min_pq.size() != 1)
		{
			min_pq.pop();
		}
		max = min_pq.top();
		min_pq.pop();
	}
	else
	{
		max = max_pq.top();
		//empty()를 이용하면 값을 계속 복제해야 하므로 시간이 좀 더 걸린다
		while (max_pq.size() != 1)
		{
			max_pq.pop();
		}
		min = max_pq.top();
		max_pq.pop();
	}

	answer.push_back(max);
	answer.push_back(min);

	return answer;
}
