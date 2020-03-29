#include <string>

using namespace std;

int solution(string dartResult)
{
	int nums[4];
	nums[0] = 0;

	int idx = 0;
	int i = 0;
	while (i < dartResult.length())
	{
		//숫자일 경우
		if ('0' <= dartResult[i] && dartResult[i] <= '9')
		{
			idx++;

			if (dartResult[i] == '1')
			{
				if (dartResult[i + 1] == '0')
				{
					nums[idx] = 10;
					i++;
				}
				else
				{
					nums[idx] = 1;
				}
			}
			else
			{
				nums[idx] = dartResult[i] - '0';
			}
		}
		else if (dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T')
		{
			if (dartResult[i] == 'D')
			{
				nums[idx] = nums[idx] * nums[idx];
			}
			else if (dartResult[i] == 'T')
			{
				nums[idx] = nums[idx] * nums[idx] * nums[idx];
			}
		}
		else if (dartResult[i] == '*' || dartResult[i] == '#')
		{
			if (dartResult[i] == '*')
			{
				nums[idx - 1] = nums[idx - 1] * 2;
				nums[idx] = nums[idx] * 2;
			}
			else
			{
				nums[idx] = nums[idx] * (-1);
			}
		}

		i++;
	}

	int answer = nums[1] + nums[2] + nums[3];
	return answer;
}
