#include <string>
#include <vector>

using namespace std;

//n개를 from에서 by를 거쳐 to로 보낸다
//recursive하게 한다
void movehanoi(int n, int from, int by, int to, vector<vector<int>>& ret)
{
	if (n == 1)
	{
		ret.push_back({ from, to });
	}
	else
	{
		//n - 1개를 A에서 B로 옮겨 놓는다
		movehanoi(n - 1, from, to, by, ret);
		//가장 아래 원판을 A에서 C로 옮겨 놓는다
		ret.push_back({ from, to });
		//B로 옮겨 놓은 n - 1개를 A로 다시 옮긴다
		movehanoi(n - 1, by, from, to, ret);
	}
}

vector<vector<int>> solution(int n) {
	vector<vector<int>> ret;

	movehanoi(n, 1, 2, 3, ret);

	return ret;
}
