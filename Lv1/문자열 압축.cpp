#include <string>
#include <vector>

using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

int solution(string s) 
{
	int n = s.length();

	int ret = n;
	int idx = 1;
	//압축의 길이가 전체의 반을 넘어간다면
	//압축을 시도해봤자이기 때문에
	while (idx <= (n / 2))
	{
		int cmp = 0;
		int cur = 0;
		string a = "";
		string b = "";
		int samecount = 1;
		for (int i = cur; i < cur + idx; i++)
		{
			a += s[i];
		}
		cur += idx;

		for (int i = cur; i < n; i++)
		{
			b += s[i];

			//길이가 같은 순간이 온다면
			if (b.length() == idx)
			{
				//두 개가 같다면
				if (a == b)
				{
					//카운트를 올려주고
					samecount++;

					//마지막 문자라면
					if (i == n - 1)
					{
						//카운트의 자리수만큼 cmp에 더해준다
						if (samecount < 10)
						{
							cmp += 1;
						}
						else if (samecount < 100)
						{
							cmp += 2;
						}
						else if (samecount < 1000)
						{
							cmp += 3;
						}
						else if (samecount == 1000)
						{
							cmp += 4;
						}

						//마지막으로 같았던 문자의 길이를 더해준다
						cmp += idx;
					}
				}
				else
				{
					//카운트가 1이 아닐 경우
					//카운트의 자리수만큼 cmp에 더해준다
					if (samecount != 1)
					{
						if (samecount < 10)
						{
							cmp += 1;
						}
						else if (samecount < 100)
						{
							cmp += 2;
						}
						else if (samecount < 1000)
						{
							cmp += 3;
						}
						else if (samecount == 1000)
						{
							cmp += 4;
						}
					}

					//이전 길이를 더해준다
					cmp += idx;
					//a를 교체한다
					a = b;
					//카운트롤 1로 갱신해준다
					samecount = 1;

					//마지막 문자라면
					if (i == n - 1)
					{
						//b의 문자열 길이를 더해준다
						cmp += idx;
					}
				}

				//b를 flush한다
				b = "";
			}
		}

		//if문을 거치지 않고 빠져나왔다면
		if (b.length() != 0)
		{
			//카운트가 1이면 이전 문자의 길이와 현재 문자의 길이를 더해준다
			if (samecount != 1)
			{
				//카운트의 자리수만큼 cmp에 더해준다
				if (samecount < 10)
				{
					cmp += 1;
				}
				else if (samecount < 100)
				{
					cmp += 2;
				}
				else if (samecount < 1000)
				{
					cmp += 3;
				}
				else if (samecount == 1000)
				{
					cmp += 4;
				}
			}
			//이전 문자열과 현재 문자열의 길이를 더해준다
			cmp += idx;
			cmp += (int)b.length();
		}

		ret = min(ret, cmp);
		idx++;
	}

	return ret;
}
