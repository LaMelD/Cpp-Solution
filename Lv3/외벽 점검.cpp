#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) 
{
	int answer = 9;

	sort(dist.begin(), dist.end(), [](int a, int b) { return a > b; });

	int ret;
	for (int i = 0; i < n; i++)
	{
		vector<int> selected;
		ret = 1;
		int dsize = dist.size();
		bool allcover = false;

		while (ret <= dsize && !allcover)
		{
			allcover = true;
			selected.clear();
			for (int i = 0; i < ret; i++)
			{
				selected.push_back(dist[i]);
			}

			do
			{
				allcover = true;
				int si = 0;
				int wi = 0;

				int start = weak[wi];
				int end = start + selected[si];
				while (1)
				{
					if (start <= weak[wi] && weak[wi] <= end)
					{
						wi++;
						if (weak.size() <= wi)
						{
							allcover = true;
							break;
						}
					}
					else
					{
						si++;
						if (ret <= si)
						{
							allcover = false;
							break;
						}

						start = weak[wi];
						end = start + selected[si];
					}
				}

				if (allcover)
				{
					answer = answer < ret ? answer : ret;
				}
			} while (prev_permutation(selected.begin(), selected.end()));

			ret++;
		}

		weak[0] += n;
		sort(weak.begin(), weak.end());
	}

	if (answer == 9)
	{
		return -1;
	}

	return answer;
}
