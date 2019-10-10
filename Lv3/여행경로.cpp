#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool flag;
vector<string> ans;

void dfs(vector<vector<string>>& ticket, vector<bool>& visit, string from, int idx, int cnt, int& tsize)
{
	if (flag)
	{
		return;
	}

	if (visit[idx])
	{
		return;
	}
	visit[idx] = true;

	ans.push_back(from);

	if (cnt == tsize)
	{
		flag = true;
		return;
	}

	for (int i = 0; i < tsize; i++)
	{
		if (ticket[i][0] == from && !visit[i] && !flag)
		{
			dfs(ticket, visit, ticket[i][1], i, cnt + 1, tsize);
		}
	}

	if (!flag)
	{
		ans.pop_back();
	}

	visit[idx] = false;
}

vector<string> solution(vector<vector<string>> tickets)
{
	ans.clear();
	flag = false;
	int tsize = tickets.size();
	vector<bool> visit(tsize + 1, 0);

	sort(tickets.begin(), tickets.end());

	dfs(tickets, visit, "ICN", tsize, 0, tsize);

	return ans;
}
