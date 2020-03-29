#include <string>
#include <vector>
#include <queue>

#include <iostream>

using namespace std;

struct cmp
{
	bool operator()(int a, int b)
	{
		return a > b;
	}
};

//첫 셔틀은 9시 정각에 있다
string solution(int n, int t, int m, vector<string> timetable)
{
	priority_queue<int, vector<int>, cmp> pq;
	int arrive;

	for (int i = 0; i < timetable.size(); i++)
	{
		string tmp = "";
		tmp += timetable[i][0];
		tmp += timetable[i][1];
		arrive = stoi(tmp) * 60;
		tmp = "";
		tmp += timetable[i][3];
		tmp += timetable[i][4];
		arrive += stoi(tmp);

		pq.push(arrive);
	}

	int n_cnt = 0;
	int m_cnt = 0;
	int tt = 9 * 60;
	while (n_cnt != n)
	{
		n_cnt++;
		m_cnt = 0;
		while (m_cnt != m)
		{
			if (pq.empty())
			{
				break;
			}

			arrive = pq.top();
			if (tt < arrive)
			{
				break;
			}

			pq.pop();
			m_cnt++;
		}

		if (m_cnt == m && n_cnt == n)
		{
			arrive--;
			break;
		}

		if (n_cnt == n)
		{
			arrive = tt;
			break;
		}

		tt += t;
	}
	int H = arrive / 60;
	int M = arrive % 60;
	string answer = "";
	if (H < 10)
	{
		answer += '0';
	}
	answer += to_string(H);
	answer += ':';
	if (M < 10)
	{
		answer += '0';
	}
	answer += to_string(M);
	return answer;
}
