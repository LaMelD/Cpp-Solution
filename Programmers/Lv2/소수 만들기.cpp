#include <vector>
#include <iostream>
using namespace std;

//소수판별
bool is_prime(int n)
{
	if (n == 1) return false;

	if (n % 2 == 0)
	{
		if (n == 2) return true;
		return false;
	}

	for (int i = 3; i < n / 2; i++)
	{
		if (n % i == 0) return false;
	}

	return true;
}

int solution(vector<int> nums)
{
	int cnt = 0;
	for (int i = 0; i < nums.size() - 2; i++)
	{
		for (int j = i + 1; j < nums.size() - 1; j++)
		{
			for (int k = j + 1; k < nums.size(); k++)
			{
				if (is_prime(nums[i] + nums[j] + nums[k])) cnt++;
			}
		}
	}

	return cnt;
}
