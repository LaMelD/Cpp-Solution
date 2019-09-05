#include <string>
#include <vector>
#include <iostream>

using namespace std;

//2진수로 표현했을 때 1의 갯수를 세는 함수
int one_cnt(int n) 
{
	int a = 0;
	int ret = 0;
	while (n != 0) 
	{
		a = n % 2;
		n = n / 2;
		if (a == 1) ret++;
	}
	return ret;
}

int solution(int n) 
{
	int cnt = one_cnt(n);

	int cmp = n + 1;
	while (1) 
	{
		//2진수로 표현했을 때 1의 갯수가 같은 다음 숫자를 찾는다
		if (cnt == one_cnt(cmp))
			return cmp;
		cmp++;
	}
}
