#include <string>
#include <vector>
#include <iostream>

using namespace std;

//완전탐색해버렸다...
//메모리 절약과 접근속도 향상 및 함수에서 값을 바꾸기 위해 &사용
void DFS(vector<int>& numbers, int target, int sum, int idx, int& ans)
{
	//마지막 까지 다 사용했는가
	if (idx == numbers.size() - 1)
	{
		//sum이 타겟과 같은가
		if (sum == target)
		{
			ans++;
		}
		return;
	}
	idx++;
	//sum에 더해서
	DFS(numbers, target, sum + numbers[idx], idx, ans);
	//sum에 빼서
	DFS(numbers, target, sum - numbers[idx], idx, ans);
}

int solution(vector<int> numbers, int target)
{
	int ans = 0;

	DFS(numbers, target, numbers[0], 0, ans);
	DFS(numbers, target, -numbers[0], 0, ans);

	return ans;
}
