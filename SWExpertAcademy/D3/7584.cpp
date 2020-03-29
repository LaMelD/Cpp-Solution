#include <iostream>
#include <string>
#include <vector>

typedef unsigned long long ull;

using namespace std;

//4의 배수가 아닌 짝수번째는 1
//4의 배수인 짝수는 0
//홀수인 경우에는 (n - 1)/2한 값을 재귀적으로 확인한다
//num이 0 또는 1이면 0
int solution(ull num)
{
	int ret;
	if (num == 0 || num == 1)
	{
		return 0;
	}

	if (num % 2 == 0)
	{
		if (num % 4 == 0)
			return 0;
		else
			return 1;
	}
	else
	{
		ret = solution((num - 1) / 2);
	}

	return ret;
}

int main()
{
	//입출력 가속
	cin.tie(NULL);
	cout.sync_with_stdio(false);

	int T;
	cin >> T;
	string s;
	for (int tc = 1; tc <= T; tc++)
	{
		ull n;
		cin >> n;
		
		cout << '#' << tc << " ";
		cout << solution(n - 1) << '\n';
	}

	return 0;
}
