#include <string>
#include <vector>

using namespace std;

//피보나치
//피보나치 판별법을 알아야한다
int solution(int n)
{
	vector<int> Fibo = { 1, 1 };

	for (int i = 2; i < n + 1; i++)
	{
		Fibo.push_back((Fibo[i - 1] + Fibo[i - 2]) % 1000000007);
	}

	return Fibo[n];
}
