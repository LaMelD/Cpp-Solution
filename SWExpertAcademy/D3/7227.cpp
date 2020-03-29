//시간초과로 터져버렸다
//완전탐색을 너무 길게 해버렸다
//쓸데없는 경우의 수를 찾는데 시간을 너무 허비했다
#include <iostream>
#include <vector>
#include <queue>

typedef long long ll;

using namespace std;

struct cmp;
struct node;
ll get_v_size(node);
ll solution(int, vector<node>);

struct node {
	int xpos = 0;
	int ypos = 0;
	int i;
	int j;
	ll size = 0;
};

struct cmp {
	bool operator()(node a, node b) {
		return b.size < a.size;
	}
};

ll get_v_size(node n)
{
	ll x = n.xpos;
	ll y = n.ypos;
	return x * x + y * y;
}

ll solution(int n, vector<node> jpos)
{
	//초기화
	int complete = n / 2;
	int match_cnt = 0;
	vector<bool> is_match(n);
	vector<priority_queue<node, vector<node>, cmp>> v_pq(n);
	vector<vector<node>> v(n, vector<node>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			v[i][j].xpos = jpos[j].xpos - jpos[i].xpos;
			v[i][j].ypos = jpos[j].ypos - jpos[i].ypos;
			v[j][i].xpos = v[i][j].xpos * (-1);
			v[j][i].ypos = v[i][j].ypos * (-1);
			v[i][j].size = get_v_size(v[i][j]);
			v[j][i].size = v[i][j].size;
			v[i][j].i = i; v[i][j].j = j;
			v[j][i].i = j; v[j][i].j = i;

			v_pq[i].push(v[i][j]);
			v_pq[j].push(v[j][i]);
		}
	}

	//xpos와 ypos만 사용
	node vectorsum;
	while (match_cnt != complete)
	{
		for (int i = 0; i < n; i++)
		{
			if (is_match[i]) continue;

			for (int j = i + 1; j < n; j++)
			{
				if (is_match[j]) continue;

				if (v_pq[i].top().size == v_pq[j].top().size)
				{
					if (v_pq[i].top().i == v_pq[j].top().j && v_pq[i].top().j == v_pq[j].top().i)
					{
						match_cnt++;
						node tmp_p, tmp_m;
						tmp_p.xpos = vectorsum.xpos + v_pq[i].top().xpos;
						tmp_p.ypos = vectorsum.ypos + v_pq[i].top().ypos;
						tmp_m.xpos = vectorsum.xpos - v_pq[i].top().xpos;
						tmp_m.ypos = vectorsum.ypos - v_pq[i].top().ypos;

						if (get_v_size(tmp_p) < get_v_size(tmp_m))
						{
							vectorsum.xpos = tmp_p.xpos;
							vectorsum.ypos = tmp_p.ypos;
						}
						else
						{
							vectorsum.xpos = tmp_m.xpos;
							vectorsum.ypos = tmp_m.ypos;
						}

						is_match[i] = true;
						is_match[j] = true;
						break;
					}
				}
			}
			if (!is_match[i])
			{
				v_pq[i].pop();
			}
		}
	}

	return get_v_size(vectorsum);
}

int main()
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		int n;
		cin >> n;
		node input;
		vector<node> jpos;
		for (int i = 0; i < n; i++)
		{
			cin >> input.xpos >> input.ypos;
			jpos.push_back(input);
		}

		cout << '#' << tc << ' ';
		cout << solution(n, jpos) << '\n';
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//시간초과로 터져버렸다
//전역변수와 고정길이를 배열을 사용해보자
#include <iostream>
#include <vector>
#define MAX 987987654321

typedef long long ll;

using namespace std;

struct node {
	int x;
	int y;
};

ll min(ll a, ll b)
{
	return a < b ? a : b;
}

ll solve(vector<node> v, vector<bool>& visit, int& n)
{
	//DFS함수에서 나누어온 것을 구체화한다
	vector<node> part1;
	vector<node> part2;
	for (int i = 0; i < n; i++)
	{
		if (visit[i])
		{
			part1.push_back(v[i]);
		}
		else
		{
			part2.push_back(v[i]);
		}
	}

	ll x = 0;
	ll y = 0;
	//여기서 나누어진 벡터를 더하고 빼기 때문에
	//하나의 노드를 다른 하나의 노드로 짝지을 필요가 없다.
	//이 부분에서 많이 헤맸다
	//나중에 백터를 다 더해주어야 하기 때문에 굳이 미리 짝지어 놓을 필요가 없다
	//즉 짝을 필요가 없는 것이다
	for (int i = 0; i < n / 2; i++)
	{
		x += (part1[i].x - part2[i].x);
		y += (part1[i].y - part2[i].y);
	}
	//만들어진 벡터의 크기를 리턴한다
	return x * x + y * y;
}

//n/2개를 뽑는다
//2부분으로 나눌수 있는 모든 경우의 수를 넣어준다
//visit한 개수가 n / 2이면 solve를 불러와서 현재 상황대로 나누었을 경우
//가질 수 있는 벡터의 합을 구한다.
void DFS(int idx, int cnt, vector<node>& v, vector<bool>& visit, int& n, ll& ret)
{
	cnt++;
	visit[idx] = true;
	if (cnt == n / 2)
	{
		//이전에 가지고 있던 벡터의 크기와 비교하여 작은 것을 갖는다
		ret = min(solve(v, visit, n), ret);
	}
	else
	{
		for (int i = idx + 1; i < n; i++)
		{
			if (!visit[i])
			{
				DFS(i, cnt, v, visit, n, ret);
			}
		}
	}
	visit[idx] = false;
	cnt--;
}

int main()
{
	cin.tie(0);
	cout.sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		int n;
		cin >> n;
		node nv;
		vector<node> v;
		vector<bool> visit(n);
		ll ret = MAX;
		for (int i = 0; i < n; i++)
		{
			cin >> nv.x >> nv.y;
			v.push_back(nv);
		}
		DFS(0, 0, v, visit, n, ret);

		cout << '#' << tc << " ";
		cout << ret << endl;
	}
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//위와 같은 아이디어
//전역변수와 고정길이 배열을 사용하니 성공했다
#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <vector>
using namespace std;
#define INF 987987654321

//입력값을 저장시킬 구조체
struct Point {
	int x;
	int y;
};

int t, n, cnt;
bool visited[21];
Point p[21];
long long res;

void calcVector() {
	vector<Point> selected;
	vector<Point> unSelected;
	for (int i = 0; i < n; i++) {
		if (visited[i]) {
			selected.push_back(p[i]);
		}
		else {
			unSelected.push_back(p[i]);
		}
	}

	long long x = 0, y = 0;
	for (int i = 0; i < n / 2; i++) {
		x += (selected.at(i).x - unSelected.at(i).x);
		y += (selected.at(i).y - unSelected.at(i).y);
	}
	if (res > y * y + x * x) {
		res = y * y + x * x;
	}
}

void dfs(int v)
{
	cnt++;
	visited[v] = true;
	if (cnt == n / 2) {
		calcVector();
	}
	else {
		for (int i = v + 1; i < n; i++) {
			if (!visited[i]) {
				dfs(i);
			}
		}
	}
	visited[v] = false;
	cnt--;
}

void init() {
	memset(visited, 0, sizeof(visited));
	memset(p, 0, sizeof(p));
	res = INF;
	cnt = 0;
}

int main() {

	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		init();
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> p[i].x >> p[i].y;
		}
		dfs(0);
		printf("#%d %lld\n", tc, res);
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//다른 사람의 좋은 코딩 :: 실행시간이 매우 짧다 -> 연구가 필요해보인다
#include <iostream>
using namespace std;

int T, N, half;
long long x[20], y[20], s_x, s_y, m;

void backtrack(int index, int s, long long v_x, long long v_y) {
	if (index == half) {
		long long v = v_x * v_x + v_y * v_y;
		m = m > v ? v : m;
	}
	else {
		int len = half + index + 1;
		for (int i = s; i < len; i++)
			backtrack(index + 1, i + 1, v_x - x[i], v_y - y[i]);
	}
}

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		s_x = s_y = 0;
		for (int i = 1; i < N; i++) {
			cin >> x[i] >> y[i];
			s_x += x[i], s_y += y[i];
			x[i] *= 2, y[i] *= 2;
		}
		cin >> x[0] >> y[0];
		s_x -= x[0]; s_y -= y[0];
		half = N / 2;
		m = 1e15;
		backtrack(1, 1, s_x, s_y);
		printf("#%d %lld\n", t, m);
	}
}
