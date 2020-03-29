#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Entry
{
	int score = 0;
	int solved = 0;
};

int main()
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);

	int TC; 
	cin >> TC;

	for (int tc = 1; tc <= TC; tc++)
	{
		int n, t, p; 
		cin >> n >> t >> p;

		p--;

		Entry entries[2000];
		int ProblemScore[2000] = { 0 , };
		vector<vector<int>> solved_problem(n);

		string s;
		getline(cin, s, '\n');
		for (int i = 0; i < n; i++)
		{
                        //문제 해결 여부를 얻는 방법에 있어서 하나씩 입력을 받으면 시간초과
                        //따라서 문자열로 입력을 받고 0, 1을 판단한다
			getline(cin, s, '\n');
			int idx = 0;
			for (int j = 0; j < s.length(); j++)
			{
				if (s[j] == '1')
				{
					ProblemScore[idx]++;
					entries[i].solved++;
					solved_problem[i].push_back(idx++);
				}
				else if (s[j] == '0')
				{
					idx++;
				}
			}
		}

		for (int i = 0; i < n; i++)
		{
			int limit = entries[i].solved;
			for (int j = 0; j < limit; j++)
			{
				entries[i].score += (n - ProblemScore[solved_problem[i][j]]);
			}
		}
		
		int score = entries[p].score;
		int rank = 1;

		//순서대로 자신보다 높은 점수, 같은 점수 더 많은 문제 푼, 같은 점수 같은 문제수 번호가 작은
		int tmp1, tmp2, tmp3;
		tmp1 = tmp2 = tmp3 = 0;

		for (int i = 0; i < n; i++)
		{
			if (i == p)
			{
				continue;
			}

			if (entries[p].score < entries[i].score)
			{
				tmp1++;
			}
			else if (entries[p].score == entries[i].score)
			{
				if (entries[p].solved < entries[i].solved)
				{
					tmp2++;
				}
				else if (entries[p].solved == entries[i].solved)
				{
					if (i < p)
					{
						tmp3++;
					}
				}
			}
		}

		rank += tmp1 + tmp2 + tmp3;

		cout << '#' << tc << ' ';
		cout << score << ' ' << rank << '\n';
	}
}
