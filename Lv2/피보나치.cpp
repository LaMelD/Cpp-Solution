#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
	vector<int> Fibo = { 0, 1 };

	for (int i = 2; i <= n; i++)
	{
		Fibo.push_back((Fibo[i - 1] + Fibo[i - 2]) % 1234567);
	}
	return Fibo[n];
}
