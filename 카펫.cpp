#include <string>
#include <vector>
#include <cmath>

using namespace std;

//테두리 부분 1칸만 brown으로 되어있다는 가정일 경우
vector<int> solution(int brown, int red)
{
	int sum = red + brown;
	int limit = (int)sqrt(sum);
	int sero;
	int garo;
	for (sero = 3; sero <= limit; sero++)
	{
		if (sum % sero == 0)
		{
			garo = sum / sero;
			//전체에서 테두리 부분을 제거 한 부분의 넓이가 red와 같은가
			if ((sero - 2) * (garo - 2) == red)
			{
				return { garo, sero };
			}
		}
	}
	return { 0, 0 };
}
/////////////////////////////////////////////////////////////////////////////////
#include <string>
#include <vector>
#include <cmath>

using namespace std;

//red가 중앙에 배치되어야 하고, 테두리 brown이 몇 칸이든 상관 없을 경우
vector<int> solution(int brown, int red)
{
	vector<int> answer;
	bool flag = false;
	int garo, sero = 1;
	int limit = (int)sqrt(red);
	//sero <= garo 조건
	while (sero <= limit)
	{
		if (red % sero == 0)
		{
			garo = red / sero;
			int n = 0;
			int b = 0;
			//b가 brown의 개수와 같다면 break
			while (b <= brown)
			{
				//b == brown
				if (b == brown)
				{
					flag = true;
					break;
				}
				//b != brown
				else
				{
					n++;
					//전체 넓이에서 red를 빼준 값을 b에 적용
					b = (sero + 2 * n) * (garo + 2 * n) - red;
				}
			}

			if (flag)
			{
				return {garo + 2 * n, sero + 2 * n};
			}
		}
		sero++;
	}
	return {0, 0};
}
