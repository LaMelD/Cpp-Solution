#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//수를 나열했을 때 가장 작은 값부터 시작하여 가장 큰 값으로 간다
/*
예 { 1, 2, 3 }
1 2 3
1 3 2	첫번째 실행
2 1 3
2 3 1
3 1 2
3 2 1	마지막 유효 실행
1 2 3	return false하고 초기상태로 돌려놓는다
	초기상태 { 1, 2, 3 }
으로 만들고 return false 한다
*/
bool nextpermutation(vector<int>::iterator first, vector<int>::iterator last)
{
	//size가 0일 때
	if (first == last)
	{
		return false;
	}
	vector<int>::iterator i = last - 1;
	//size가 1일 때
	if (first == i)
	{
		return false;
	}

	while (1)
	{
		vector<int>::iterator tmp1, tmp2;

		tmp1 = i;
		if (*--i < *tmp1)
		{
			tmp2 = last - 1;
			while (1)
			{
				if (*i < *tmp2)
				{
					break;
				}
				tmp2--;
			}

			iter_swap(i, tmp2);
			reverse(tmp1, last);
			return true;
		}

		if (i == first)
		{
			reverse(first, last);
			return false;
		}
	}
}

//완전탐색
int solution(int n, vector<string> data)
{
	vector<int> arr = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };

	int cnt = 0;

	char ch1, ch2;
	char opcode;
	int far;
	bool flag;
	do
	{
		flag = true;

		//조건 검색
		for (int i = 0; i < n; i++)
		{
			ch1 = data[i][0];
			ch2 = data[i][2];
			opcode = data[i][3];
			far = data[i][4] - '0';

			int nowfar = -1;
			for (int j = 0; j < 8; j++)
			{
				if (arr[j] == ch1 || arr[j] == ch2)
				{
					if (nowfar == -1)
					{
						nowfar = j;
					}
					else
					{
						nowfar = j - nowfar - 1;
						break;
					}
				}
			}

			switch (opcode)
			{
			case '<':
				if (nowfar >= far)
				{
					flag = false;
				}
				break;
			case '=':
				if (nowfar != far)
				{
					flag = false;
				}
				break;
			case '>':
				if (nowfar <= far)
				{
					flag = false;
				}
				break;
			}

			if (!flag)
			{
				break;
			}
		}

		if (flag)
		{
			cnt++;
		}

	} while (nextpermutation(arr.begin(), arr.end()));

	return cnt;
}
