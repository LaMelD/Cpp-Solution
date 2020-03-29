//여러가지 방법을 시도하였으나 시간복잡도 n^3을 빠져나오지 못했다
//카카오 코드 페스티벌 예선의 풀이법을 참고하여 코딩하였다
//이해하는데 오래걸렸다
//추후에 다시 풀어보는 것을 추천한다
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> data) 
{
	//data에 있는 좌표들을 x, y로 쪼개어
	//x와 y를 오름차순으로 중복없는 배열을 생성한다
	vector<int> xpoint;
	vector<int> ypoint;
	for (int i = 0; i < data.size(); i++)
	{
		xpoint.push_back(data[i][0]);
		ypoint.push_back(data[i][1]);
	}

	sort(xpoint.begin(), xpoint.end());
	sort(ypoint.begin(), ypoint.end());
	xpoint.erase(unique(xpoint.begin(), xpoint.end()), xpoint.end());
	ypoint.erase(unique(ypoint.begin(), ypoint.end()), ypoint.end());

	//S[i][j]: x좌표가 [0, (x좌표 중 i번째로 작은 값)], y좌표가 [0, (y좌표 중 j번째로 작은 값)]인 쐐기의 개수를 나타내는 S를 생성하고 초기화한다
	vector<vector<int>> S(xpoint.size(), vector<int>(ypoint.size(), 0));
	for (int i = 0; i < n; i++)
	{
		//data의 x, y를 xpoint, ypoint에 맞게 idx를 수정한다
		int x = 0, y = 0;
		for (int j = 0; j < xpoint.size(); j++)
		{
			if (data[i][0] == xpoint[j])
			{
				x = j;
				data[i][0] = x;
				break;
			}
		}

		for (int j = 0; j < ypoint.size(); j++)
		{
			if (data[i][1] == ypoint[j])
			{
				y = j;
				data[i][1] = y;
				break;
			}
		}

		//쐐기가 존재한 곳은 값을 1로 초기화한다
		S[x][y] = 1;
	}

	//S배열을 완성해준다
	//S배열의 컨셉을 완성시킨다
	for (int i = 0; i < xpoint.size(); i++)
	{
		for (int j = 0; j < ypoint.size(); j++)
		{
			//i가 0보다 크다면 위에 것을 더해준다
			if (i > 0)
			{
				S[i][j] += S[i - 1][j];
			}

			//j가 0보다 크다면 왼쪽 것을 더해준다
			if (j > 0)
			{
				S[i][j] += S[i][j - 1];
			}

			//둘다 0보다 크다면 왼쪽 상단의 것을 빼준다(중복 더하기 제거)
			if (i > 0 && j > 0)
			{
				S[i][j] -= S[i - 1][j - 1];
			}
		}
	}

	int ans = 0;
	int cnt;
	int left, right, top, bottom;
	//모든 쐐기 쌍에 대해서 판별
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			//사각형의 넓이가 0이면 continue
			if (data[i][0] == data[j][0] || data[i][1] == data[j][1])
			{
				continue;
			}

			//left, right, top, bottom을 설정한다
			left = data[i][1] < data[j][1] ? data[i][1] : data[j][1];
			right = data[i][1] < data[j][1] ? data[j][1] : data[i][1];
			top = data[i][0] < data[j][0] ? data[j][0] : data[i][0];
			bottom = data[i][0] < data[j][0] ? data[i][0] : data[j][0];

			//한 변의 길이가 1이라면 cnt를 0으로 한다
			if (right - left == 1 || top - bottom == 1)
			{
				cnt = 0;
			}
			else
			{
				//식을 보고 그림을 그려 이해하는 것을 추천한다
				cnt = S[top - 1][right - 1] - S[top - 1][left] - S[bottom][right - 1] + S[bottom][left];
			}

			//cnt(내부 쐐기의 갯수)가 0이라면 ans++한다
			if (cnt == 0)
			{
				ans++;
			}
		}
	}

	return ans;
}
