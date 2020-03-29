#include <iostream>
#include <vector>

using namespace std;

//첫번째 아이디어 
int solution(int n, vector<int> stations, int w)
{
	int div = w * 2 + 1;
	int s_idx = 0;
	int cnt = 0;
	int ans = 0;
	for (int i = 0; i <= stations.size(); i++)
	{
		int cnt;
		if (i == 0)
		{
			cnt = stations[i] - 0 - 1 - w;
			if (cnt < 0)
			{
				continue;
			}
			cnt += 2 * w;
			ans += cnt / div;
		}
		else if (i == stations.size())
		{
			cnt = n - stations[i - 1] - w;
			if (cnt < 0)
			{
				continue;
			}
			cnt += 2 * w;
			ans += cnt / div;
		}
		else
		{
			cnt = stations[i] - stations[i - 1] - 1 - w * 2;
			if (cnt < 0)
			{
				continue;
			}
			cnt += 2 * w;
			ans += cnt / div;
		}
	}
	return ans;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>

using namespace std;

//다듬은 코드
int solution(int n, vector<int> stations, int w)
{
	int div = w * 2 + 1;
	int prev = 0;
	int next;
	int ans = 0;
	for (int i = 0; i < stations.size(); i++)
	{
		next = stations[i] - w;
		int cnt = next - prev - 1;

		if (cnt > 0)
		{
			if (cnt % div == 0)
				ans += cnt / div;
			else
				ans += (cnt / div) + 1;
		}
		prev = stations[i] + w;
	}

	if (prev < n)
	{
		int cnt = n - prev;

		if (cnt % div == 0)
			ans += cnt / div;
		else
			ans += (cnt / div) + 1;
	}

	return ans;
}
