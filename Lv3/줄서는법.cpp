#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long k) {
	k = k - 1;
	//(n - 1)!을 만든다
	long long f = 1;
	for (int i = 1; i < n; i++)
	{
		f = f * (long long)i;
	}
	vector<int> answer;
	vector<bool> used(21, false);
	for (int i = n - 1; i >= 0; i--)
	{
		if (i == 0)
		{
			for (int j = 1; j <= n; j++)
			{
				if (!used[j])
				{
					answer.push_back(j);
					break;
				}
			}
			break;
		}

		int tmp = (k / f) + 1;
		int cnt = 1;
		for (int j = 1; i <= n; j++)
		{
			if (used[j])
			{
				continue;
			}

			if (cnt == tmp)
			{
				answer.push_back(j);
				used[j] = true;
				break;
			}
			cnt++;
		}
		k = k % f;
		f = f / i;

	}
	return answer;
}
