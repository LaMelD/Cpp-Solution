#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n)
{
	vector<int> ans = { 0 };
	int asize = 1;

	vector<int> tmp;
	while (asize < n)
	{
		tmp = ans;
		tmp.push_back(0);
		for (int i = ans.size() - 1; i >= 0; i--)
		{
			if (ans[i] == 1)
			{
				tmp.push_back(0);
			}
			else
			{
				tmp.push_back(1);
			}
		}

		ans = tmp;

		asize++;
	}

	return ans;
}
