//backtracking + memoization으로 풀었을 때
\#include <iostream>
#include <vector>
#define MAX 1000001

using namespace std;

vector<vector<int>> W;
vector<vector<bool>> visit;

int solution(int, vector<vector<int>>);
int solve(int&, vector<vector<int>>&, int, int);
int min(int a, int b) {
	return a > b ? b : a;
}

int main() {
	int T, n;
	cin >> T;
	vector<vector<int>> RGB;
	int i, j;
	for (i = 0; i < T; i++) {
		RGB.push_back({});
		for (j = 0; j < 3; j++) {
			cin >> n;
			RGB[i].push_back(n);
		}
	}
	cout << solution(T, RGB) << endl;
	return 0;
}

int solution(int n, vector<vector<int>> RGB) {
	W = vector<vector<int>>(n, vector<int>(3));
	visit = vector<vector<bool>>(n, vector<bool>(3));

	int MIN = MAX;
	for (int i = 0; i < 3; i++) {
		MIN = min(solve(n, RGB, 0, i), MIN);
	}

	return MIN;
}

int solve(int& n, vector<vector<int>>& RGB, int i, int j) {
	int& ret = W[i][j];

	if (i >= n - 1) {
		ret = RGB[i][j];
		return ret;
	}

	if (visit[i][j]) return ret;
	visit[i][j] = true;

	int m = MAX;
	for (int k = 0; k < 3; k++) {
		if (k == j) continue;
		m = min(m, solve(n, RGB, i + 1, k));
	}
	ret = m + RGB[i][j];

	return ret;
}


//DP로 풀었을 경우
#include <iostream>
#include <cstring>

using namespace std;

int** dp;

int min(int a, int b)
{
	return a < b ? a : b;
}

int min(int a, int b, int c)
{
	int ret = a < b ? a : b;
	ret = ret < c ? ret : c;
	return ret;
}

int main() {
	int n, ans = 0;
	cin >> n;

	dp = new int* [n];
	for (int i = 0; i < n; i++)
	{
		dp[i] = new int[3];
		memset(dp[i], 0, sizeof(int) * 3);
	}

	int R, G, B;
	cin >> R >> G >> B;
	dp[0][0] = R;
	dp[0][1] = G;
	dp[0][2] = B;
	ans = min(R, G, B);

	for (int i = 1; i < n; i++)
	{
		cin >> R >> G >> B;
		dp[i][0] = min(dp[i - 1][1] + R, dp[i - 1][2] + R);
		dp[i][1] = min(dp[i - 1][0] + G, dp[i - 1][2] + G);
		dp[i][2] = min(dp[i - 1][0] + B, dp[i - 1][1] + B);

		ans = min(dp[i][0], dp[i][1], dp[i][2]);
	}
	
	//메모리 해제
	for (int i = 0; i < n; i++)
	{
		delete[] dp[i];
	}
	delete[] dp;

	cout << ans << endl;

	return 0;
}
