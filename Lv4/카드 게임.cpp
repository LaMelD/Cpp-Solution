#include <string>
#include <vector>

using namespace std;

int max(int a, int b)
{
	return a < b ? b : a;
}

int playgame(vector<int>& left, vector<int>& right, int lidx, int ridx, vector<vector<int>>& W, int& size)
{
	if (lidx > size || ridx > size)
		return 0;

	int& ret = W[lidx][ridx];

	if (ret != 0) return ret;

	//점수를 얻을 수 있다면 무조건 갖는다
	if (right[ridx] < left[lidx])
	{
		ret += playgame(left, right, lidx, ridx + 1, W, size) + right[ridx];
	}
	else
	{
		ret += max(
			playgame(left, right, lidx + 1, ridx, W, size), 
			playgame(left, right, lidx + 1, ridx + 1, W, size)
		);
	}

	return ret;
}

int solution(vector<int> left, vector<int> right) 
{
	int answer = 0;

	int size = left.size();
	vector<vector<int>> W(size, vector<int>(size, 0));
	size--;
	answer = playgame(left, right, 0, 0, W, size);

	return answer;
}
