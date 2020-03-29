#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
	int stage;
	int playing;
	int arrive;
	bool iszero;
};

vector<int> solution(int N, vector<int> stages)
{
	vector<node> ret;

	for (int i = 1; i <= N; i++)
	{
		int arrive = 0;
		int playing = 0;
		node input;
		input.stage = i;
		for (int j = 0; j < stages.size(); j++)
		{
			if (i <= stages[j])
			{
				if (i == stages[j])
				{
					playing++;
				}
				arrive++;
			}
		}

		if (arrive == 0)
		{
			input.iszero = 1;
			ret.push_back(input);
		}
		else
		{
			input.iszero = 0;
			input.arrive = arrive;
			input.playing = playing;
			ret.push_back(input);
		}
	}

	sort(ret.begin(), ret.end(), [](node a, node b) 
		{
			//소트 조건에서 비교한다
			if (a.iszero && b.iszero)
			{
				return a.stage < b.stage;
			}

			if (a.iszero)
			{
				return false;
			}

			if (b.iszero)
			{
				return true;
			}

			long long aa, bb;
			aa = (long long)a.playing * (long long)b.arrive;
			bb = (long long)b.playing * (long long)a.arrive;
			if (aa == bb)
			{
				return a.stage < b.stage;
			}
			return aa > bb;
		}
	);

	vector<int> answer;
	for (int i = 0; i < N; i++)
	{
		answer.push_back(ret[i].stage);
	}

	return answer;
}
