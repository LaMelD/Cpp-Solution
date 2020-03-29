#include <vector>
#define MAX 987654321

using namespace std;

int min(int a, int b)
{
	return a > b ? b : a;
}

//완전 탐색 DFS를 기초로 완전탐색한다
//n : 고정값
//num : 연산을 완료한 값
//target : 목표값
//cnt : n이 쓰인 횟수
//ans : 최솟값
void solve(int& n, int num, int& target, int cnt, int& ans)
{
	int next = 0;

	//구해진 최솟값보다 cnt가 크거나, 연산 횟수가 8 초과라면 리턴해준다
	if (cnt > 8 || ans < cnt) return;

	//연산을 완료한 값이 목표값가 같다면
	if (num == target)
	{
		//ans를 조정한다
		ans = min(ans, cnt);
		return;
	}

	for (int i = 1; (i + cnt) <= 8; i++)
	{
		//현재 연산 값을 조정한다
		//i = 1 -> next = n;
		//i = 2 -> next = n * 10 + n;
		//i = 3 -> next = n * 100 + n * 10 + n;
		//...
		next = (next * 10) + n;

		//값을 조정하여 recursive하게 함수를 호출한다.
		solve(n, num + next, target, cnt + i, ans);
		solve(n, num - next, target, cnt + i, ans);
		solve(n, num * next, target, cnt + i, ans);
		solve(n, num / next, target, cnt + i, ans);
	}
}

int solution(int N, int number)
{
	int ans = MAX;
	//N으로 number를 만들고 가장 적게 쓰인 횟수를 ans에 저장한다
	solve(N, 0, number, 0, ans);

	//ans가 MAX값 그대로라면 -1을 리턴한다
	return (ans == MAX) ? -1 : ans;
}
