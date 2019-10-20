#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
	if (n == 1) return 1;
	if (n == 2) return 2;
	long long answer = 0;
	vector<long long> num(3);
	num[1] = 1;
	num[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		num.push_back((num[i - 1] + num[i - 2]) % 1234567);
	}

	answer = num.back();

	return answer;
}
