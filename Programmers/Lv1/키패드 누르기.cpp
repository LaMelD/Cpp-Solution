# include <vector>
# include <string>
# include <map>

using namespace std;

struct Point {
	int x = 0;
	int y = 0;
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

string solution(vector<int> numbers, string hand)
{
	string ans = "";
	vector<pair<int, int>> num_point = { make_pair(3,1), make_pair(0,0), make_pair(0,1), make_pair(0,2), make_pair(1,0), make_pair(1,1), make_pair(1,2), make_pair(2,0), make_pair(2,1), make_pair(2,2) };
	Point L(3, 0);
	Point R(3, 2);
	bool right = false;
	if (hand == "right")
	{
		right = true;
	}

	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
		{
			ans += 'L';
			L.x = num_point[numbers[i]].first;
			L.y = num_point[numbers[i]].second;
		}
		else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
		{
			ans += 'R';
			R.x = num_point[numbers[i]].first;
			R.y = num_point[numbers[i]].second;
		}
		else
		{
			int l_dist = abs(L.x - num_point[numbers[i]].first) + abs(L.y - num_point[numbers[i]].second);
			int r_dist = abs(R.x - num_point[numbers[i]].first) + abs(R.y - num_point[numbers[i]].second);
			if (l_dist == r_dist)
			{
				if (right)
				{
					ans += 'R';
					R.x = num_point[numbers[i]].first;
					R.y = num_point[numbers[i]].second;
				}
				else
				{
					ans += 'L';
					L.x = num_point[numbers[i]].first;
					L.y = num_point[numbers[i]].second;
				}
			}
			else if (l_dist < r_dist)
			{
				ans += 'L';
				L.x = num_point[numbers[i]].first;
				L.y = num_point[numbers[i]].second;
			}
			else
			{
				ans += 'R';
				R.x = num_point[numbers[i]].first;
				R.y = num_point[numbers[i]].second;
			}
		}
	}

	return ans;
}