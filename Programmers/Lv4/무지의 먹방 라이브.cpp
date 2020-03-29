#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct node
{
	int times = 0;
	int idx = 0;
};

int solution(vector<int> food_times, long long k)
{
	int n = food_times.size();

	//data parsing
	vector<node> ACS;
	for (int i = 0; i < n; i++)
	{
		node input;
		input.idx = i;
		input.times = food_times[i];
		ACS.push_back(input);
	}

	sort(ACS.begin(), ACS.end(), [](node a, node b)
		{
			if (a.times == b.times)
			{
				return a.idx < b.idx;
			}
			return a.times < b.times;
		}
	);

	int ACS_idx = 0;
	int before_value = 0;
	while (1)
	{
		long long tmpk = k;
		long long tmp1 = (long long)ACS[ACS_idx].times - (long long)before_value;
		long long tmp2 = (long long)n - (long long)ACS_idx;
		tmpk -= tmp1 * tmp2;
		if (tmpk < 0)
		{
			break;
		}
		else if (tmpk == 0)
		{
			k = 0;
			break;
		}

		k = tmpk;

		before_value = ACS[ACS_idx++].times;

		if (ACS_idx == n)
		{
			return -1;
		}
	}

	if (k == 0)
	{
		for (int i = 0; i < n; i++)
		{
			if (ACS[ACS_idx].times < food_times[i])
			{
				return i + 1;
			}
		}

		return -1;
	}
	else
	{
		int i = 0;
		while (1)
		{
			long long tmpk = k;
			long long tmp1 = (long long)n - (long long)ACS_idx;
			tmpk -= (long long)i * tmp1;
			if (tmpk < 0)
			{
				i--;
				k = k - tmp1 * i;
				break;
			}
			else if (tmpk == 0)
			{
				k = 0;
				break;
			}

			i++;
		}

		if (k == 0)
		{
			for (i = 0; i < n; i++)
			{
				if (before_value < food_times[i])
				{
					return i + 1;
				}
			}

			return -1;
		}
		else
		{
			i = 0;
			while (1)
			{
				if (before_value < food_times[i])
				{
					k--;
					if (k == -1)
					{
						return i + 1;
					}
				}
				i++;
				i = i % n;
			}
		}
	}

	return 0;
}

int main()
{
	int a;

	a = solution({ 3,1,2 }, 5);
	printf("%d\n", a);

	a = solution({ 4,4,4 }, 11);
	printf("%d\n", a);

	a = solution({ 3,1,2 }, 14);
	printf("%d\n", a);

	return 0;
}
