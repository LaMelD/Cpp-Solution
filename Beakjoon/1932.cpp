//첫번째 방법 메모리를 많이 차지한다
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
	int answer = 0;
	int size = triangle.size();
	vector<vector<int>> v(size, vector<int>(size));
	v[0][0] = triangle[0][0];

	for (int i = 1; i < size; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (j == 0) v[i][0] = v[i - 1][0] + triangle[i][0];
			else if (j == i) v[i][j] = v[i - 1][j - 1] + triangle[i][j];
			else v[i][j] = max(v[i - 1][j - 1] + triangle[i][j], v[i - 1][j] + triangle[i][j]);

			if (i == size - 1) answer = max(v[i][j], answer);
		}
	}
	return answer;
}

int main() {
	int T;
	int n;
	vector<vector<int>> tri;
	vector<int> tmp;
	cin >> T;
	for (int i = 0; i < T; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> n;
			tmp.push_back(n);
		}
		tri.push_back(tmp);
		tmp.clear();
	}
	cout << solution(tri) << endl;
}

//두번째 방법 -> 최적화
#include <iostream>
#include <cstring>

using namespace std;

int** dp;
int** triangle;

int max(int a, int b)
{
	return a < b ? b : a;
}

int main() {
	int n, ans;
	cin >> n;

	dp = new int* [n];
	triangle = new int* [n];
	for (int i = 1; i <= n; i++)
	{
		dp[i - 1] = new int[i];
		triangle[i - 1] = new int[i];
		for (int j = 0; j < i; j++)
		{
			cin >> triangle[i - 1][j];
		}
		memset(dp[i - 1], 0, sizeof(int) * i);
	}

	dp[0][0] = triangle[0][0];
	ans = triangle[0][0];

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (j == 0)
			{
				dp[i - 1][j] = dp[i - 2][j] + triangle[i - 1][j];
			}
			else if (j == i - 1)
			{
				dp[i - 1][j] = dp[i - 2][j - 1] + triangle[i - 1][j];
			}
			else
			{
				dp[i - 1][j] = max(dp[i - 2][j - 1], dp[i - 2][j]) + triangle[i - 1][j];
			}
			ans = max(ans, dp[i - 1][j]);
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		delete[] triangle[i];
		delete[] dp[i];
	}
	delete[] triangle;
	delete[] dp;

	cout << ans << endl;

	return 0;
}
