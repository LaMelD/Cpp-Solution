#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> B;

//for visit & memo
struct node
{
	node() : left(false), right(false), top(false), bottom(false) {}

	//왼쪽과 여기
	bool left;
	//오른쪽과 여기
	bool right;
	//위쪽과 여기
	bool top;
	//아래쪽과 여기
	bool bottom;
};

struct point
{
	point() : x(0), y(0) {}
	int x;
	int y;

	void operator=(point a) 
	{
		this->x = a.x;
		this->y = a.y;
	}
};

bool operator==(point a, point b)
{
	if (a.x == b.x && a.y == b.y)
		return true;
	return false;
}

bool operator<(point a, point b)
{
	if (a.x == b.x)
		return a.y < b.y;

	if (a.y == b.y)
		return a.x < b.y;
}

struct pointset
{
	point p1; //n,n과 상대적으로 가까운 것
	point p2; //n,n과 상대적으로 먼 것
};

bool operator==(pointset a, pointset b)
{
	if (a.p1 == b.p1 && a.p2 == b.p2)
		return true;

	if (a.p1 == b.p2 && a.p2 == b.p1)
		return true;

	return false;
}

struct W
{
	int movecount;
	pointset pos;
};

bool moveleft(pointset pos, int& n)
{
	if (0 <= pos.p2.y - 1 && B[pos.p1.x][pos.p1.y - 1] == 0 && B[pos.p2.x][pos.p2.y - 1] == 0)
		return true;
	return false;
}

bool moveright(pointset pos, int& n)
{
	if (pos.p1.y + 1 < n && B[pos.p1.x][pos.p1.y + 1] == 0 && B[pos.p2.x][pos.p2.y + 1] == 0)
		return true;
	return false;
}

bool moveup(pointset pos, int& n)
{
	if (0 <= pos.p2.x - 1 && B[pos.p1.x - 1][pos.p1.y] == 0 && B[pos.p2.x - 1][pos.p2.y] == 0)
		return true;
	return false;
}

bool movedown(pointset pos, int& n)
{
	if (pos.p1.x + 1 < n && B[pos.p1.x + 1][pos.p1.y] == 0 && B[pos.p2.x + 1][pos.p2.y] == 0)
		return true;
	return false;
}

//state
//가로로 있을 때 :: 0
//세로로 있을 때 :: 1
bool rotate_p1_forward(pointset pos, int& n, int state)
{
	if (state == 0)
	{
		if (0 <= pos.p1.x - 1 && B[pos.p2.x - 1][pos.p2.y] == 0 && B[pos.p1.x - 1][pos.p1.y] == 0)
			return true;
	}
	else
	{
		//p1, p2가 스왑되어 들어가야함
		if (pos.p1.y + 1 < n && B[pos.p2.x][pos.p2.y + 1] == 0 && B[pos.p1.x][pos.p1.y + 1] == 0)
			return true;
	}

	return false;
}

bool rotate_p1_reverse(pointset pos, int& n, int state)
{
	if (state == 0)
	{
		//p1, p2가 스왑되어 들어가야함
		if (pos.p1.x + 1 < n && B[pos.p2.x + 1][pos.p2.y] == 0 && B[pos.p1.x + 1][pos.p1.y] == 0)
			return true;
	}
	else
	{
		if (0 <= pos.p1.y - 1 && B[pos.p2.x][pos.p2.y - 1] == 0 && B[pos.p1.x][pos.p1.y - 1] == 0)
			return true;
	}

	return false;
}

bool rotate_p2_forward(pointset pos, int& n, int state)
{
	if (state == 0)
	{
		if (pos.p2.x + 1 < n && B[pos.p1.x + 1][pos.p1.y] == 0 && B[pos.p2.x + 1][pos.p2.y] == 0)
			return true;
	}
	else
	{
		//p1, p2가 스왑되어 들어가야함
		if (0 <= pos.p2.y - 1 && B[pos.p1.x][pos.p1.y - 1] == 0 && B[pos.p2.x][pos.p2.y - 1] == 0)
			return true;
	}

	return false;
}

bool rotate_p2_reverse(pointset pos, int& n, int state)
{
	if (state == 0)
	{
		//p1, p2가 스왑되어 들어가야함
		if (0 <= pos.p2.x - 1 && B[pos.p1.x - 1][pos.p1.y] == 0 && B[pos.p2.x - 1][pos.p2.y] == 0)
			return true;
	}
	else
	{
		if (pos.p2.y + 1 < n && B[pos.p1.x][pos.p1.y + 1] == 0 && B[pos.p2.x][pos.p2.y + 1] == 0)
			return true;
	}

	return false;
}

void Swap(point& a, point& b)
{
	point tmp;
	tmp = a;
	a = b;
	b = tmp;
}

int solution(vector<vector<int>> board)
{
	int n = board.size();
	vector<vector<node>> visit(n, vector<node>(n));
	B = board;
	queue<W> q;

	pointset pos;
	pos.p1.y = 1;
	W pushing;
	pushing.movecount = 0;
	pushing.pos = pos;

	q.push(pushing);
	int ret = 0;
	while (!q.empty())
	{
		pos = q.front().pos;
		ret = q.front().movecount;
		q.pop();

		if (pos.p1.x == (n - 1) && pos.p1.y == (n - 1))
		{
			return ret;
		}

		int state = -1;

		//visit의 여부를 확인하여 이동 가능한 모든 구역을 조사
		//조사 후에 queue에 넣는다

		//가로로 있을 경우
		if (pos.p1.x == pos.p2.x)
		{
			if (visit[pos.p1.x][pos.p1.y].left && visit[pos.p2.x][pos.p2.y].right)
			{
				continue;
			}
			visit[pos.p1.x][pos.p1.y].left = true;
			visit[pos.p2.x][pos.p2.y].right = true;

			state = 0;
		}
		//세로로 있을 경우
		else
		{
			if (visit[pos.p1.x][pos.p1.y].top && visit[pos.p2.x][pos.p2.y].bottom)
			{
				continue;
			}
			visit[pos.p1.x][pos.p1.y].top = true;
			visit[pos.p2.x][pos.p2.y].bottom = true;

			state = 1;
		}

		if (moveleft(pos, n))
		{
			pushing.pos = pos;
			pushing.pos.p1.y--;
			pushing.pos.p2.y--;
			pushing.movecount = ret + 1;
			q.push(pushing);
		}

		if (moveright(pos, n))
		{
			pushing.pos = pos;
			pushing.pos.p1.y++;
			pushing.pos.p2.y++;
			pushing.movecount = ret + 1;
			q.push(pushing);
		}

		if (moveup(pos, n))
		{
			pushing.pos = pos;
			pushing.pos.p1.x--;
			pushing.pos.p2.x--;
			pushing.movecount = ret + 1;
			q.push(pushing);
		}

		if (movedown(pos, n))
		{
			pushing.pos = pos;
			pushing.pos.p1.x++;
			pushing.pos.p2.x++;
			pushing.movecount = ret + 1;
			q.push(pushing);
		}

		if (rotate_p1_forward(pos, n, state))
		{
			if (state == 0)
			{
				pushing.pos = pos;
				pushing.pos.p2.x--;
				pushing.pos.p2.y++;
				pushing.movecount = ret + 1;
				q.push(pushing);
			}
			else
			{
				//p1, p2가 스왑되어 들어가야함
				pushing.pos = pos;
				pushing.pos.p2.x++;
				pushing.pos.p2.y++;
				Swap(pushing.pos.p1, pushing.pos.p2);
				pushing.movecount = ret + 1;
				q.push(pushing);
			}
		}

		if (rotate_p1_reverse(pos, n, state))
		{
			if (state == 0)
			{
				//p1, p2가 스왑되어 들어가야함
				pushing.pos = pos;
				pushing.pos.p2.x++;
				pushing.pos.p2.y++;
				Swap(pushing.pos.p1, pushing.pos.p2);
				pushing.movecount = ret + 1;
				q.push(pushing);
			}
			else
			{
				pushing.pos = pos;
				pushing.pos.p2.x++;
				pushing.pos.p2.y--;
				pushing.movecount = ret + 1;
				q.push(pushing);
			}
		}

		if (rotate_p2_forward(pos, n, state))
		{
			if (state == 0)
			{
				pushing.pos = pos;
				pushing.pos.p1.x++;
				pushing.pos.p1.y--;
				pushing.movecount = ret + 1;
				q.push(pushing);
			}
			else
			{
				//p1, p2가 스왑되어 들어가야함
				pushing.pos = pos;
				pushing.pos.p1.x--;
				pushing.pos.p1.y--;
				Swap(pushing.pos.p1, pushing.pos.p2);
				pushing.movecount = ret + 1;
				q.push(pushing);
			}
		}

		if (rotate_p2_reverse(pos, n, state))
		{
			if (state == 0)
			{
				//p1, p2가 스왑되어 들어가야함
				pushing.pos = pos;
				pushing.pos.p1.x--;
				pushing.pos.p1.y--;
				Swap(pushing.pos.p1, pushing.pos.p2);
				pushing.movecount = ret + 1;
				q.push(pushing);
			}
			else
			{
				pushing.pos = pos;
				pushing.pos.p1.x--;
				pushing.pos.p1.y++;
				pushing.movecount = ret + 1;
				q.push(pushing);
			}
		}
	}

	int answer = 0;
	return answer;
}
