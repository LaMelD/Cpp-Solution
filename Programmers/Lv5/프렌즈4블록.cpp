#include <string>
#include <vector>
#include <queue>

using namespace std;

bool is_square_same(vector<string>& w, int i, int j)
{
	if (w[i][j] == w[i][j + 1] && w[i][j] == w[i + 1][j] && w[i][j] == w[i + 1][j + 1])
	{
		return true;
	}

	return false;
}

void flush_block(vector<string>& w, int x, int y)
{
	w[x][y] = 'a';
	w[x + 1][y] = 'a';
	w[x][y + 1] = 'a';
	w[x + 1][y + 1] = 'a';
}

//비어있다는 의미로 'a'를 넣자
int solution(int m, int n, vector<string> board)
{
	queue<pair<int,int>> q;
	while (1)
	{
		for (int i = 0; i < m - 1; i++)
		{
			for (int j = 0; j < n - 1; j++)
			{
				if (board[i][j] == 'a')
				{
					continue;
				}

				if (is_square_same(board, i, j))
				{
					q.push(make_pair(i, j));
				}
			}
		}

		if (q.empty())
		{
			break;
		}

		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			flush_block(board, x, y);
		}

		for (int j = 0; j < n; j++)
		{
			int cnt = 0;
			for (int i = m - 1; i >= 0; i--)
			{
				if (board[i][j] != 'a' && cnt == 0)
				{
					continue;
				}
				else if (board[i][j] != 'a' && cnt != 0)
				{
					board[i + cnt][j] = board[i][j];
					board[i][j] = 'a';
				}
				else
				{
					cnt++;
				}
			}
		}
	}
	int answer = 0;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 'a')
			{
				answer++;
			}
		}
	}

	return answer;
}
