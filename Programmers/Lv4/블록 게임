#include <string>
#include <vector>

using namespace std;

int getBlockShape(vector<vector<int>>& board, int x, int y)
{
	int block_num = board[x][y];

	//1 :: 철 모양
	if (board[x][y + 1] == block_num && board[x - 1][y + 1] == block_num &&
		board[x][y + 2] == block_num)
	{
		return 1;
	}

	//2 :: 세로 ㄴ
	if (board[x][y - 1] == block_num && board[x - 1][y - 1] == block_num &&
		board[x - 2][y - 1] == block_num)
	{
		return 2;
	}

	//3 :: 세로 역ㄴ
	if (board[x][y + 1] == block_num && board[x - 1][y + 1] == block_num &&
		board[x - 2][y + 1] == block_num)
	{
		return 3;
	}

	//4 :: 가로 ㄴ
	if (board[x][y - 1] == block_num && board[x - 1][y - 1] == block_num && 
		board[x][y + 1] == block_num)
	{
		return 4;
	}

	//5 :: 가로 역ㄴ
	if (board[x][y + 1] == block_num && board[x][y + 2] == block_num &&
		board[x - 1][y + 2] == block_num)
	{
		return 5;
	}

	//0 :: 못 지우는 모양
	return 0;
}

//확인하는 블록을 지울 수 있는지 확인한다
//직사각형을 만들 수 있는가?
//가장 높은 것을 제외한 것 이외의 것 위쪽에 아무것도 존재하지 않는가
bool canDeleteBlock(vector<vector<int>>& board, int x, int y, int shape)
{
	if (shape == 0)
	{
		return false;
	}

	switch (shape)
	{
	case 1 :
		for (int i = x - 1; i > 0; --i)
		{
			if (board[i][y + 2] != 0)
			{
				return false;
			}
		}
		return true;
	case 2 :
		return true;
	case 3 :
		return true;
	case 4 :
		for (int i = x - 1; i > 0; --i)
		{
			if (board[i][y + 1] != 0)
			{
				return false;
			}
		}
		return true;
	case 5 :
		for (int i = x - 1; i > 0; --i)
		{
			if (board[i][y + 1] != 0)
			{
				return false;
			}
		}
		return true;
	}
}

//해당 블록을 0으로 만들어준다
void DeleteBlock(vector<vector<int>>& board, int x, int y, int shape)
{
	board[x][y] = 0;

	switch (shape)
	{
	case 1:
		board[x][y + 1] = 0;
		board[x - 1][y + 1] = 0;
		board[x][y + 2] = 0;
		return;
	case 2:
		board[x][y - 1] = 0;
		board[x - 1][y - 1] = 0;
		board[x - 2][y - 1] = 0;
		return;
	case 3:
		board[x][y + 1] = 0;
		board[x - 1][y + 1] = 0;
		board[x - 2][y + 1] = 0;
		return;
	case 4://
		board[x][y - 1] = 0;
		board[x][y + 1] = 0;
		board[x - 1][y - 1] = 0;
		return;
	case 5:
		board[x][y + 1] = 0;
		board[x][y + 2] = 0;
		board[x - 1][y + 2] = 0;
		return;
	}
}

int solution(vector<vector<int>> board)
{
	int ret = 0;
	int n = board.size();
	//-1로 둘러싸인 board을 생성한다
	vector<vector<int>> nboard(n + 2, vector<int>(n + 2, -1));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			nboard[i][j] = board[i - 1][j - 1];
		}
	}

	bool is_change;
	do
	{
		is_change = false;

		int x, y;

		for (y = 1; y <= n; y++)
		{
			for (x = 1; x <= n; x++)
			{
				int shape;
				if (nboard[x][y] != 0)
				{
					shape = getBlockShape(nboard, x, y);
					if (canDeleteBlock(nboard, x, y, shape))
					{
						ret++;
						is_change = true;
						DeleteBlock(nboard, x, y, shape);
						y = 0;
					}
					break;
				}
			}
		}

	} while (is_change);

	return ret;
}

int main()
{
	int result = solution({ 
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 4, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 4, 4, 0, 0, 0}, 
		{0, 0, 0, 0, 3, 0, 4, 0, 0, 0}, 
		{0, 0, 0, 2, 3, 0, 0, 0, 5, 5}, 
		{1, 2, 2, 2, 3, 3, 0, 0, 0, 5}, 
		{1, 1, 1, 0, 0, 0, 0, 0, 0, 5} });

	result = solution({
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 6, 0, 0},
		{0, 0, 0, 0, 5, 0, 6, 6, 6, 0},
		{0, 0, 0, 4, 5, 5, 5, 0, 0, 0},
		{0, 0, 3, 4, 4, 4, 8, 0, 0, 0},
		{1, 2, 3, 3, 3, 8, 8, 0, 0, 0},
		{1, 2, 2, 2, 0, 7, 8, 0, 0, 0},
		{1, 1, 0, 0, 7, 7, 7, 0, 0, 0} });
	
	return 0;
}
