#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct POINT
{
	int x;
	int y;
};

struct BLOCK
{
	char ch = 0;
	POINT pos1 = { -1, -1 };
	POINT pos2 = { -1, -1 };
};

bool checkbetween(vector<string>& board, POINT pos1, POINT pos2)
{
	if (pos1.x == pos2.x)
	{
		for (int i = pos1.y + 1; i < pos2.y; i++)
		{
			if (board[pos1.x][i] != '.')
			{
				return false;
			}
		}
	}
	else
	{
		for (int i = pos1.x + 1; i < pos2.x; i++)
		{
			if (board[i][pos1.y] != '.')
			{
				return false;
			}
		}
	}

	return true;
}

bool can_erase(vector<string>& board, BLOCK block)
{
	POINT pos1, pos2;
	pos1 = block.pos1;
	pos2 = block.pos2;

	//같은 선상
	if (pos1.x == pos2.x || pos1.y == pos2.y)
	{
		return checkbetween(board, pos1, pos2);
	}
	//좌상우하
	else if (pos1.y < pos2.y)
	{
		POINT tmp1 = { pos1.x, pos2.y };
		POINT tmp2 = { pos2.x, pos1.y };

		if (checkbetween(board, pos1, tmp1) && checkbetween(board, tmp1, pos2) && board[tmp1.x][tmp1.y] == '.')
		{
			return true;
		}

		if (checkbetween(board, pos1, tmp2) && checkbetween(board, tmp2, pos2) && board[tmp2.x][tmp2.y] == '.')
		{
			return true;
		}
	}
	//우상좌하
	else
	{
		POINT tmp1 = { pos1.x, pos2.y };
		POINT tmp2 = { pos2.x, pos1.y };

		if (checkbetween(board, tmp1, pos1) && checkbetween(board, tmp1, pos2) && board[tmp1.x][tmp1.y] == '.')
		{
			return true;
		}

		if (checkbetween(board, pos1, tmp2) && checkbetween(board, pos2, tmp2) && board[tmp2.x][tmp2.y] == '.')
		{
			return true;
		}
	}

	return false;
}

string solution(int m, int n, vector<string> board)
{
	string answer = "";
	vector<BLOCK> blocks;
	BLOCK block;
	POINT pos;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == '*' || board[i][j] == '.')
			{
				continue;
			}

			block.ch = board[i][j];
			pos.x = i;
			pos.y = j;

			bool is_in = false;
			for (int k = 0; k < blocks.size(); k++)
			{
				if (blocks[k].ch == block.ch)
				{
					blocks[k].pos2 = pos;
					is_in = true;
					break;
				}
			}

			if (!is_in)
			{
				block.pos1 = pos;
				blocks.push_back(block);
			}
		}
	}

	sort(blocks.begin(), blocks.end(), [](BLOCK a, BLOCK b) 
		{
			return a.ch < b.ch;
		}
	);

	bool is_changed;
	while (!blocks.empty())
	{
		is_changed = false;
		for (int i = 0; i < blocks.size(); i++)
		{
			if (can_erase(board, blocks[i]))
			{
				is_changed = true;
				board[blocks[i].pos1.x][blocks[i].pos1.y] = '.';
				board[blocks[i].pos2.x][blocks[i].pos2.y] = '.';
				answer += blocks[i].ch;
				blocks.erase(blocks.begin() + i);
				break;
			}
		}

		if (!is_changed)
		{
			return "IMPOSSIBLE";
		}
	}

	return answer;
}
