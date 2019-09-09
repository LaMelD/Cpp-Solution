#include <iostream>
#include <vector>

using namespace std;

int solution(int n) 
{
	int ans = 0;
    //마지막 도달부터 거꾸로 간다
	while (1)
	{
        //순간이동이 가능하다면 점프
		if (n % 2 == 0)
		{
            //cnt가 올라가지 않는다
			n = n / 2;
		}
		else
		{
            //점프하면 cnt++
			n = n - 1;
			ans++;
		}

        //시작지점이라면 break;
		if (n == 0) break;
	}
	return ans;
}
