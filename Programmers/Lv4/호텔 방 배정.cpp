// 정확성 성공
# include <vector>
# include <string>
# include <map>

typedef long long ll;

using namespace std;

vector<long long> solution(ll k, vector<ll> room_number)
{
	vector<ll> ans;
	map<ll, bool> rooms;
	for (int i = 0; i < room_number.size(); i++)
	{
		while (rooms.find(room_number[i]) != rooms.end())
		{
			room_number[i]++;
		}
		ans.push_back(room_number[i]);
		rooms.insert(pair<ll, bool>(room_number[i], true));
	}
	return ans;
}

// 정확성 효율성 성공
# include <vector>
# include <string>
# include <map>

typedef long long ll;

using namespace std;

ll getParent(map<ll, ll>& rooms, ll room_num)
{
	ll ret;
	if (rooms.find(room_num) == rooms.end())
	{
		rooms.insert(pair<ll, ll>(room_num, room_num + 1));
		ret =  room_num;
	}
	else
	{
		ret = getParent(rooms, rooms.at(room_num));
	}
	rooms.at(room_num) = ret + 1;
	return ret;
}

vector<long long> solution(ll k, vector<ll> room_number)
{
	vector<ll> ans;
	// <current node, parent node>
	map<ll, ll> rooms;
	for (int i = 0; i < room_number.size(); i++)
	{
		if (rooms.find(room_number[i]) == rooms.end())
		{
			ans.push_back(room_number[i]);
			rooms.insert(pair<ll, ll>(room_number[i], room_number[i] + 1));
		}
		else
		{
			ans.push_back(getParent(rooms, room_number[i] + 1));
		}
	}
	return ans;
}