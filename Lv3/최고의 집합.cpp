#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s)
{
	vector<int> ans(n, 0);

	if (s < n)
	{
		return { -1 };
	}

	int mok = s / n;
	int namoji = s % n;

	for (int i = n - 1; i >= 0; i--)
	{
		if (namoji == 0)
		{
			ans[i] = mok;
		}
		else
		{
			ans[i] = mok + 1;
			namoji--;
		}
	}

	return ans;
}
