#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> baseball)
{
	int answer = 0;
	int bs = baseball.size();
	string tmp;
	bool flag;
	int st, ba, a, b, c;
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			if (i == j) continue;
			for (int k = 1; k < 10; k++)
			{
				if (k == i || k == j) continue;
				flag = true;
				//숫자야구에서 제시된 숫자와 ijk를 자리수에 맞게 비교한다
				for (int w = 0; w < bs; w++)
				{
					st = 0; ba = 0;
					tmp = to_string(baseball[w][0]);
					a = tmp[0] - '0'; b = tmp[1] - '0'; c = tmp[2] - '0';

					if (i == a) st++;
					if (j == b) st++;
					if (k == c) st++;
					if (i == b || i == c) ba++;
					if (j == a || j == c) ba++;
					if (k == a || k == b) ba++;

					//스트라이크 수와 볼 수가 같지 않다면 flag를 false로 하고 break
					if (st != baseball[w][1] || ba != baseball[w][2])
					{
						flag = false;
						break;
					}
				}
				if (flag) answer++;
			}
		}
	}
	return answer;
}
