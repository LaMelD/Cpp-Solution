#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
	int start;
	int end;
};

int max(int a, int b)
{
	return a < b ? b : a;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int solution(vector<string> lines)
{
	vector<node> proc(lines.size());
	vector<node> intersection;

	int i, j;
	string s;
	int time = 0;
	//proc 배열을 초기화 한다
	for (i = 0; i < lines.size(); i++)
	{
		//h
		s = "";
		for (j = 11; j < 13; j++)
		{
			s += lines[i][j];
		}
		time = stoi(s);

		//m
		s = "";
		for (j = 14; j < 16; j++)
		{
			s += lines[i][j];
		}
		time = time * 60 + stoi(s);

		//s
		s = "";
		for (j = 17; j < 19; j++)
		{
			s += lines[i][j];
		}
		time = time * 60 + stoi(s);

		//ss
		s = "";
		for (j = 20; j < 23; j++)
		{
			s += lines[i][j];
		}
		time = time * 1000 + stoi(s);

		proc[i].end = time;

		//during
		s = "";
		for (j = 24; lines[i][j] != 's'; j++)
		{
			s += lines[i][j];
		}
		time = stod(s) * 1000;
		proc[i].start = proc[i].end - time + 1;
	}

//먼저 해본 방법 :: 2개가 처리가 안된다...
//방법도 모르겠다.
#if 0
	node tmp;
	int cnt = 0;
	while (1)
	{
		//초당 최대 처리량
		cnt++;
		for (i = 0; i < proc.size() - 1; i++)
		{
			//i의 끝이 i + 1의 시작이 999ms보다 작다면 
			if (proc[i + 1].start < proc[i].end + 999)
			{
				//i의 시작과 i + 1의 시작을 비교한다
				tmp.start = max(proc[i].start, proc[i + 1].start);
				//i의 끝과 i + 1의 끝을 비교한다
				tmp.end = min(proc[i + 1].end, proc[i].end);
				//교집합 백터를 만들어주고 푸시한다
				intersection.push_back(tmp);
			}
		}
		//교집합 가능하다면 교집합 한다
		//proc배열을 교집합으로 교체한다
		proc = intersection;
		//교집합 배열을 비운다
		intersection.clear();

		//교집합을 진행한 결과의 수가 1이면
		//초당 최대 처리량을 ++하여 break;
		if (proc.size() == 1)
		{
			cnt++;
			break;
		}
		//교집합을 진행한 결과의 수가 0이면
		//break;
		else if (proc.size() == 0)
		{
			break;
		}
	}
	return cnt;
#endif

//두번째 방법 :: 성공
//대조해서 모두 확인해본다
#if 1
	int maximum = 0;
	int tmp;
        //모든 경우의 수를 탐색하여 최대값을 
	for (int i = 0; i < proc.size(); i++)
	{
		tmp = 0;

		for (int j = 0; j < proc.size(); j++)
		{
                        //j.시작 이 i.시작 과 i.시작-999 사이에 있으면 tmp++
			if (proc[i].start - 999 <= proc[j].start && proc[j].start <= proc[i].start)
			{
				tmp++;
			}
                        //j.끝 이 i.시작 과 i.시작-999 사이에 있으면 tmp++;
			else if (proc[i].start - 999 <= proc[j].end && proc[j].end <= proc[i].start)
			{
				tmp++;
			}
                        //j.시작 이 i.시작-999 보다 작거나 같고 j.끝 이 i.시작보다 크다면 tmp++
			else if (proc[j].start <= proc[i].start - 999 && proc[i].start < proc[j].end)
			{
				tmp++;
			}
		}

		maximum = max(tmp, maximum);
	}

	return maximum;
#endif
}
