#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const char num[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

string nx(int number, int n)
{
	string ret = "";

	while (1)
	{
		int tmp = number % n;
		ret = num[tmp] + ret;
		number = number / n;

		if (number == 0)
		{
			break;
		}
	}

	return ret;
}

string solution(int n, int t, int m, int p) 
{
	int number = 0;
	int p_count = 0;
	int m_count = 0;

	string answer = "";

	while (1)
	{
		string str = nx(number, n);

		for (int i = 0; i < str.length(); i++)
		{
			if ((p - 1) == m_count)
			{
				answer.push_back(str[i]);
				p_count++;
			}

			if (p_count == t)
			{
				break;
			}

			m_count++;
			m_count = m_count % m;
		}

		if (p_count == t)
		{
			break;
		}

		number++;
	}

	return answer;
}
