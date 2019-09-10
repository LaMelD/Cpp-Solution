#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//target :: 타겟 넘버
//m_cnt :: * 3한 횟수
//p_cnt :: + 1한 횟수
//max_m_cnt :: * 3을 할 수 있는 최대 횟수
//Back_tracking
int solve(int target, int m_cnt, int p_cnt, int max_m_cnt)
{
	//목표에 도달 했는가
	if (target == 1)
	{
		//더한 횟수가 곱한 횟수의 2배인가
		if (m_cnt * 2 == p_cnt)
			return 1;
	}

	//곱한 횟수 또는 더한 횟수가 최대를 넘었는가
	if (m_cnt > max_m_cnt || p_cnt > max_m_cnt * 2) return 0;

	//목표가 1이하이면 return
	if (target <= 1) return 0;

	int ret = 0;

	//target이 3의 배수이고 현재 상황이 * 3을 실행할 수 있는 상황인가
  //*........+++인 상황
  //더한횟수 - (곱한횟수 * 2)가 2이상이어야 실행할 수 있는 상황이다
	if (target % 3 == 0 && (p_cnt - m_cnt * 2) >= 2)
	{
		// * 3 해서 재귀적으로 진행한다
		ret += solve(target / 3, m_cnt + 1, p_cnt, max_m_cnt);
	}

	// + 1 해서 재귀적으로 진행한다
	ret += solve(target - 1, m_cnt, p_cnt + 1, max_m_cnt);

	return ret;
}

int solution(int n)
{
	int ans = solve(n, 0, 0, log(n) / log(3));

	return ans;
}
