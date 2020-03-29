#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> solution(vector<int> now_time, vector<int> apoint_time)
{
	for (int i = 2; i >= 0; i--)
	{
		now_time[i] = apoint_time[i] - now_time[i];
	}

	if (now_time[2] < 0)
	{
		now_time[1] -= 1;
		now_time[2] += 60;
	}

	while (1)
	{
		if (now_time[1] < 0)
		{
			now_time[0] -= 1;
			now_time[1] += 60;
		}
		else 
		{
			break;
		}
	}

	while (1)
	{
		if (now_time[0] < 0)
		{
			now_time[0] += 24;
		}
		else
		{
			break;
		}
	}

	vector<string> ret;
	string tmp = "";
	for (int i = 0; i < 3; i++)
	{
		if (now_time[i] < 10) tmp += '0';
		tmp += to_string(now_time[i]);
		ret.push_back(tmp);
		tmp = "";
	}

	return ret;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		string nti, ati;
		cin >> nti;
		cin >> ati;
		vector<int> now_time, apoint_time;
		string tmp1 = "", tmp2 = "";
		for (int j = 0; j < 8; j++)
		{
			if (nti[j] == ':')
			{
				now_time.push_back(stoi(tmp1));
				apoint_time.push_back(stoi(tmp2));
				tmp1 = "";
				tmp2 = "";
				continue;
			}
			tmp1 += nti[j];
			tmp2 += ati[j];
		}
		now_time.push_back(stoi(tmp1));
		apoint_time.push_back(stoi(tmp2));

		vector<string> ans = solution(now_time, apoint_time);
		cout << '#' << test_case << " ";
		cout << ans[0] << ":" << ans[1] << ":" << ans[2] << endl;
	}
	return 0;
}
