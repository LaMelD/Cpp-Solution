#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct user
{
	string uid;
	string name;
};

struct state
{
	bool rflag;
	int uid_idx;
};

int get_uid_idx(string uid, vector<user>& U)
{
	for (int i = 0; i < U.size(); i++)
	{
		bool flag = true;
		int j = 0;
		for (j = 0; j < uid.length(); j++)
		{
			if (U[i].uid[j] == NULL)
			{
				flag = false;
				break;
			}

			if (U[i].uid[j] != uid[j])
			{
				flag = false;
				break;
			}
		}
		if (flag && U[i].uid[j] == NULL && uid[j] == NULL)
		{
			return i;
		}
	}

	return -1;
}

vector<string> split(string s)
{
	vector<string> ret;

	stringstream ss(s);

	string str;
	while (ss >> str) 
	{
		ret.push_back(str);
	}

	return ret;
}

//enter 0 leave 1
vector<string> solution(vector<string> record)
{
	vector<state> STATE;
	vector<user> USER;
	int i, j;

	for (i = 0; i < record.size(); i++)
	{
		j = 0;
		user uinput;
		state sinput;

		vector<string> info = split(record[i]);

		if (info[0] == "Enter")
		{
			sinput.rflag = 0;
			uinput.uid = info[1];
			uinput.name = info[2];

			int idx = get_uid_idx(uinput.uid, USER);

			if (idx == -1) 
			{
				USER.push_back(uinput);
				sinput.uid_idx = USER.size() - 1;
			}
			else
			{
				USER[idx].name = uinput.name;
				sinput.uid_idx = idx;
			}
			STATE.push_back(sinput);
		}
		else if (info[0] == "Leave")
		{
			sinput.rflag = 1;
			int idx = get_uid_idx(info[1], USER);
			sinput.uid_idx = idx;

			STATE.push_back(sinput);
		}
		else if (info[0] == "Change")
		{
			uinput.uid = info[1];
			uinput.name = info[2];

			int idx = get_uid_idx(uinput.uid, USER);
			USER[idx].name = uinput.name;
		}
	}

	vector<string> ret;

	for (i = 0; i < STATE.size(); i++)
	{
		string rtmp = "";
		rtmp += USER[STATE[i].uid_idx].name;
		rtmp += "님이 ";
		if (STATE[i].rflag)
		{
			rtmp += "나갔습니다.";
		}
		else
		{
			rtmp += "들어왔습니다.";
		}
		ret.push_back(rtmp);
	}

	return ret;
}
