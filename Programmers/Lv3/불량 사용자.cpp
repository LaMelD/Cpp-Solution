# include <vector>
# include <string>
# include <algorithm>
# include <map>

using namespace std;

// 두 문자열을 비교한다.
bool compare(string a, string b)
{
	bool ret = true;

	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == '*')
		{
			continue;
		}

		if (a[i] != b[i])
		{
			return false;
		}
	}

	return ret;
}

int solution(vector<string> user_id, vector<string> banned_id) 
{
	vector<vector<string>> ban_set;
	vector<int> ban_set_count;
	for (int i = 0; i < banned_id.size(); i++)
	{
		vector<string> bans;
		for (int j = 0; j < user_id.size(); j++)
		{
			if (banned_id[i].length() != user_id[j].length())
			{
				continue;
			}

			if (compare(banned_id[i], user_id[j]))
			{
				bans.push_back(user_id[j]);
			}
		}
		if (bans.size() != 0)
		{
			ban_set.push_back(bans);
			ban_set_count.push_back(bans.size());
		}
	}

	map<vector<string>, int> num_set;
	
	int fullcount = ban_set_count[0];

    // 가질 수 있는 모든 경우의 수를 구한다.(최악 : 2^24)
	for (int i = 1; i < ban_set_count.size(); i++)
	{
		fullcount *= ban_set_count[i];
	}
	
    // 모든 경우의 수에 대입한다.
	for (int i = 0; i < fullcount; i++)
	{
		int count = i;
		vector<string> nums;
        // ex   1,0,0
        //      2,0,0
        //      0,1,0
        //      0,0,1
        //      1,0,1
        //      2,0,1
        //      0,1,1
        //      1,1,1
        //      2,1,1
        // 각 유저id를 넣었을 때 중복 검사를 실시하고 중복된다면 더 이상 진행하지 않고 현 경우의 수를 버린다.
		for (int j = 0; j < ban_set_count.size(); j++)
		{
			bool is_in = false;
			for (int k = 0; k < nums.size(); k++)
			{
				if (nums[k] == ban_set[j][count % ban_set_count[j]])
				{
					is_in = true;
					break;
				}
			}

			if (is_in)
			{
				break;
			}
			
			nums.push_back(ban_set[j][count % ban_set_count[j]]);
			count /= ban_set_count[j];
		}
		if (nums.size() == ban_set_count.size())
		{
            // set에 넣었을 때 중복을 방지하기 위해서 map을 사용한다.
            // map에 넣었을 때 중복을 제거하기 위해서 sort를 진행한다.
			sort(nums.begin(), nums.end());
			num_set.insert(pair<vector<string>, int>(nums, 0));
		}
	}

	int ans = num_set.size();
	return ans;
}