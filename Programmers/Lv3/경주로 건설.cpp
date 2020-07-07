# include <string>
# include <vector>
# include <queue>

using namespace std;

// from
// 0 : start point
// 1 : left
// 2 : top
// 3 : right
// 4 : bottom
struct Node
{
	int i = -1;
	int j = -1;
	int corner = -1;
	int length = -1;
	vector<int> from;
	Node()
	{
		this->i = -1;
		this->j = -1;
		this->corner = -1;
		this->length = -1;
	}
	Node(int i, int j)
	{
		this->i= i;
		this->j = j;
		this->corner = 0;
		this->length = 0;
		this->from = { 0 };
	}
	Node(int i, int j, int corner, int length, vector<int> from)
	{
		this->i = i;
		this->j = j;
		this->corner = corner;
		this->length = length;
		this->from = from;
	}
};

int solution(vector<vector<int>> board) 
{
	//bfs 시작
	queue<Node> q;
	vector<vector<Node>> visit = vector<vector<Node>>(board.size(), vector<Node>(board.size(), Node()));

	q.push(Node(0, 0));

	while (!q.empty())
	{
		Node now = q.front();
		q.pop();

		if (now.i < 0 || board.size() <= now.i || now.j < 0 || board.size() <= now.j)
		{
			continue;
		}

		if (board[now.i][now.j] == 1)
		{
			continue;
		}

		if (visit[now.i][now.j].corner != -1)
		{
			int v_cost = visit[now.i][now.j].length * 100 + visit[now.i][now.j].corner * 500;
			int cost = now.length * 100 + now.corner * 500;

			if (cost < v_cost)
			{
				visit[now.i][now.j] = now;
			}
			else if (cost == v_cost)
			{
				for (int i = 0; i < now.from.size(); i++)
				{
					visit[now.i][now.j].from.push_back(now.from[i]);
					continue;
				} 
			}
			else
			{
				continue;
			}
		}
		else
		{
			visit[now.i][now.j] = now;
		}

		Node next = now;
		for (int i = 0; i < now.from.size(); i++)
		{
			switch (now.from[i])
			{
			case 0:
				//from start
				//toright
				q.push(Node(now.i, now.j + 1, now.corner, now.length + 1, vector<int>(1, 1)));
				//tobottom
				q.push(Node(now.i + 1, now.j, now.corner, now.length + 1, vector<int>(1, 2)));
				break;
			case 1:
				//from left
				//toright
				q.push(Node(now.i, now.j + 1, now.corner, now.length + 1, vector<int>(1, 1)));
				//tobottom
				q.push(Node(now.i + 1, now.j, now.corner + 1, now.length + 1, vector<int>(1, 2)));
				//totop
				q.push(Node(now.i - 1, now.j, now.corner + 1, now.length + 1, vector<int>(1, 4)));
				break;
			case 2:
				//from top
				//toright
				q.push(Node(now.i, now.j + 1, now.corner + 1, now.length + 1, vector<int>(1, 1)));
				//tobottom
				q.push(Node(now.i + 1, now.j, now.corner, now.length + 1, vector<int>(1, 2)));
				//toleft
				q.push(Node(now.i, now.j - 1, now.corner + 1, now.length + 1, vector<int>(1, 3)));
				break;
			case 3:
				//from right
				//tobottom
				q.push(Node(now.i + 1, now.j, now.corner + 1, now.length + 1, vector<int>(1, 2)));
				//toleft
				q.push(Node(now.i, now.j - 1, now.corner, now.length + 1, vector<int>(1, 3)));
				//totop
				q.push(Node(now.i - 1, now.j, now.corner + 1, now.length + 1, vector<int>(1, 4)));
				break;
			case 4:
				//from bottom
				//toright
				q.push(Node(now.i, now.j + 1, now.corner + 1, now.length + 1, vector<int>(1, 1)));
				//toleft
				q.push(Node(now.i, now.j - 1, now.corner + 1, now.length + 1, vector<int>(1, 3)));
				//totop
				q.push(Node(now.i - 1, now.j, now.corner, now.length + 1, vector<int>(1, 4)));
				break;
			}
		}
	}

	return visit[board.size() - 1][board.size() - 1].length * 100 + visit[board.size() - 1][board.size() - 1].corner * 500;
}
