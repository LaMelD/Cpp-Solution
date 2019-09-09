#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
	int answer = 1;
	while (1)
	{
		if (a % 2 != 0) a += 1;

		if (b % 2 != 0) b += 1;

		a = a / 2;
		b = b / 2;

		if (a == b) break;

		answer++;
	}
	return answer;
}
