//n퀸 문제의 기본적인 풀이법
#include <string>
#include <vector>

using namespace std;

int num;
vector<int> col;
int ans;

bool promising(int n)
{
	int i = 1;
	bool ret = true;
	while (i < n && ret)
	{
		if (col[n] == col[i] || abs(col[n] - col[i]) == n - i)
			ret = false;
		i++;
	}
	return ret;
}

void queens(int n)
{
	if (promising(n))
	{
		if (n == num)
		{
			ans++;
		}
		else
		{
			for (int i = 1; i <= num; i++)
			{
				col[n + 1] = i;
				queens(n + 1);
			}
		}
	}
}

int solution(int n) {
	ans = 0;
	num = n;
	col = vector<int>(n + 1);

	queens(0);

	return ans;
}
