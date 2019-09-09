#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//유클리드 호제법
int getGCD(int n, int m)
{
	int big = max(n, m);
	int small = min(n, m);

	int mod;
	while (1)
	{
		mod = big % small;

		if (mod == 0) break;

		big = small;
		small = mod;
	}
	return small;
}

//n개의 최소공배수
int solution(vector<int> arr)
{
	int gcd;
	int result = arr[0];

	for (int i = 1; i < arr.size(); i++)
	{
		gcd = getGCD(result, arr[i]);

		result = result * arr[i] / gcd;
	}

	return result;
}
