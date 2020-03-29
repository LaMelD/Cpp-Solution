#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct cmp {
	bool operator()(int a, int b)
	{
		return a > b;
	}
};

int solution(vector<int> A, vector<int> B)
{
	sort(A.begin(), A.end(), cmp());
	sort(B.begin(), B.end(), cmp());

	int ans = 0;
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i] < B[i])
		{
			ans++;
		}
		else
		{
			A.erase(A.begin() + i);
			B.pop_back();
			i--;
		}
	}
	return ans;
}
