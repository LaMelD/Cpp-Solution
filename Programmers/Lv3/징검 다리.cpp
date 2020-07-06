# include <vector>
# include <string>
# include <algorithm>

using namespace std;

// 1번 방법 : 효율성 시간초과
// k 길이의 구간의 각각의 최대값을 구하고 그 중에 최소값을 구한다.
int solution(vector<int> stones, int k) {
	vector<int> jump;
	int m = -1;
	for (int i = 0; i < k; i++)
	{
		jump.push_back(stones[i]);
		if (m < stones[i])
		{
			m = stones[i];
		}
	}

	int min = m;

	for (int i = k; i < stones.size(); i++)
	{
		jump.push_back(stones[i]);
		jump.erase(jump.begin());

		int max = -1;
		for (int j = 0; j < k; j++)
		{
			if (max < jump[j])
			{
				max = jump[j];
			}
		}

		if (max < min)
		{
			min = max;
		}
	}

	return min;
}

// 2번 방법 : 이분 탐색
vector<int> getMinMax(vector<int> target)
{
	sort(target.begin(), target.end());
	return { target.front(), target.back() };
}

int solution(vector<int> stones, int k) 
{
	vector<int> min_max = getMinMax(stones); // [0] = min, [1] = max
	int l, r, m;
	l = min_max[0];
	r = min_max[1];
	while (l <= r)
	{
		m = (l + r) / 2;
		int count = 0;
		bool check = false;
		for (int i = 0; i < stones.size(); i++)
		{
			if (stones[i] - m <= 0)
			{
				count++;
			}
			else
			{
				count = 0;
			}

			if (k <= count)
			{
				check = true;
				break;
			}
		}

		if (check)
		{
			r = m - 1;
		}
		else
		{
			l = m + 1;
		}
	}

	int ans = l;
	return ans;
}