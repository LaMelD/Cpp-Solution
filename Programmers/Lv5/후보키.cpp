#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//2 3 5가 후보키로 확정 되었을 경우
//2 3 5에 관련된 것을 더 이상 실행하지 않지만
//이후에 실행되는 3 5가 후보키라면 2 3 5는 더 이상 후보키가 아니기 때문에
//후보키로 판단된 것들을 저장해 놓고
//마지막에 최소성을 판단하는 것이 옳다고 판단된다

vector<vector<int>> ans;

bool is_Same(string a, string b)
{
	if (a.length() != b.length())
	{
		return false;
	}

	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] != b[i])
		{
			return false;
		}
	}

	return true;
}

void dfs(vector<vector<string>>& R, int idx, vector<string> stack, int& maxi, vector<int> to_ans)
{
	//현재 키로 설정한 것이 유일한 값인지 확인
	bool can_key = true;
	for (int i = 0; i < stack.size(); i++)
	{
		for (int j = 0; j < stack.size(); j++)
		{
			if (i == j) continue;

			if (is_Same(stack[i], stack[j]))
			{
				can_key = false;
				break;
			}
		}
		if (!can_key)
		{
			break;
		}
	}

	//유일하다면 ans에 가능한 후보키를 푸시하고 리턴
	//더 이상 진행하지 않는다
	if (can_key)
	{
		ans.push_back(to_ans);
		return;
	}

	//유일하지 않다면 뒷 부분을 수행한다
	for (int i = idx + 1; i < maxi; i++)
	{
		for (int j = 0; j < stack.size(); j++)
		{
			stack[j] += R[j][i];
		}
		
		to_ans.push_back(i);
		dfs(R, i, stack, maxi, to_ans);
		to_ans.pop_back();

		for (int j = 0; j < stack.size(); j++)
		{
			for (int k = 0; k < R[j][i].length(); k++)
			{
				stack[j].pop_back();
			}
		}
	}
}

int solution(vector<vector<string>> relation)
{
	ans.clear();

	int maxi = relation[0].size();

	vector<string> stack(relation.size(), "");
	vector<int> to_ans;

	//각각의 속성으로 시작한다
	for (int j = 0; j < maxi; j++)
	{
		for (int i = 0; i < relation.size(); i++)
		{
			stack[i] = relation[i][j];
		}

		to_ans.push_back(j);
		dfs(relation, j, stack, maxi, to_ans);
		to_ans.pop_back();
	}

	//여기서 최소성을 확인한다
	int ret = 0;
	int i_idx, j_idx;
	for (int i = 0; i < ans.size(); i++)
	{
		for (int j = 0; j < ans.size(); j++)
		{
			if (i == j) continue;

			if (ans[i].size() >= ans[j].size()) continue;

			i_idx = 0;
			j_idx = 0;
			while (i_idx < ans[i].size() && j_idx < ans[j].size())
			{
				if (ans[i][i_idx] == ans[j][j_idx])
				{
					i_idx++;
					j_idx++;
				}
				else
				{
					j_idx++;
				}
			}
			if (i_idx == ans[i].size())
			{
				//j를 지운다
				ans.erase(ans.begin() + j);

				//j가 i 뒤에 있다면 j값만 조정해주고
				if (i < j)
				{
					j--;
				}
				//j가 i 앞에 있다면 i, j값 모두 조정한다
				else
				{
					i--;
					j--;
				}
			}
		}
	}

	ret = ans.size();

	return ret;
}
