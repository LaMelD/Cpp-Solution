//brute force(완전탐색)로 풀었을 경우
//시간초과
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string ans;

void solve(vector<int> W, int idx, string s, int cnt, int n)
{
	if (W[idx] == 0 || ans != "")
		return;

	W[idx] -= 1;
	cnt++;
	if (idx == 0 || idx == 2)
	{
		s += '0';
	}
	else
	{
		s += '1';
	}

	if (cnt == n)
	{
		if (ans == "")
		{
			ans = s;
		}
		return;
	}

	if (idx == 0 || idx == 2)
	{
		solve(W, 0, s, cnt, n);
		solve(W, 1, s, cnt, n);
	}
	else
	{
		solve(W, 2, s, cnt, n);
		solve(W, 3, s, cnt, n);
	}
}

int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		ans = "";
		vector<int> Array(4);
		cin >> Array[0] >> Array[1] >> Array[2] >> Array[3];

		int n = Array[0] + Array[1] + Array[2] + Array[3];

		solve(Array, 0, "0", 0, n);
		solve(Array, 1, "0", 0, n);
		solve(Array, 2, "1", 0, n);
		solve(Array, 3, "1", 0, n);

		cout << '#' << tc << ' ';
		if (ans == "")
		{
			cout << "impossible\n";
		}
		else
		{
			cout << ans << '\n';
		}
	}

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//dp로 풀었을 경우
//생각해내는데 어려움이 많다
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//a,b,c,d,마지막 자리
string dp[21][21][21][21][2];
bool visit[21][21][21][21][2];

//back_tacking기반 재귀함수
void fill_dp(int a, int b, int c, int d, int bit)
{
	string& ret = dp[a][b][c][d][bit];
	
	if (visit[a][b][c][d][bit]) return;
	visit[a][b][c][d][bit] = true;

	//현재 마지막 비트가 0이고 쓸 수 있는 a(00)가 남아 있는가
	if (a != 0 && bit == 0)
	{
		//a(00)를 추가하기 전 단계로 간다
		fill_dp(a - 1, b, c, d, 0);
		//a(00)를 추가하기 전 단계의 길이가 0이 아니면 a(00)을 추가하는 의미인 0을 추가한다
		if (dp[a - 1][b][c][d][0].length() != 0)
		{
			ret = dp[a - 1][b][c][d][0] + "0";
			return;
		}
	}

	//현재 마지막 비트가 1이고 쓸 수 있는 b(01)가 남아 있는가
	if (b != 0 && bit == 1)
	{
		//b(01)를 추가하기 전 단계로 간다
		fill_dp(a, b - 1, c, d, 0);
		//b(01)를 추가하기 전 단계의 길이가 0이 아니면 b(01)을 추가하는 의미인 1을 추가한다
		if (dp[a][b - 1][c][d][0].length() != 0)
		{
			ret = dp[a][b - 1][c][d][0] + "1";
			return;
		}
	}

	//현재 마지막 비트가 0이고 쓸 수 있는 c(10)가 남아 있는가
	if (c != 0 && bit == 0)
	{
		//c(10)를 추가하기 전 단계로 간다
		fill_dp(a, b, c - 1, d, 1);
		//c(10)를 추가하기 전 단계의 길이가 0이 아니면 c(10)을 추가하는 의미인 0을 추가한다
		if (dp[a][b][c - 1][d][1].length() != 0)
		{
			ret = dp[a][b][c - 1][d][1] + "0";
			return;
		}
	}

	//현재 마지막 비트가 1이고 쓸 수 있는 d(11)가 남아 있는가
	if (d != 0 && bit == 1)
	{
		//d(11)를 추가하기 전 단계로 간다
		fill_dp(a, b, c, d - 1, 1);
		//d(11)를 추가하기 전 단계의 길이가 0이 아니면 d(11)을 추가하는 의미인 1을 추가한다
		if (dp[a][b][c][d - 1][1].length() != 0)
		{
			ret = dp[a][b][c][d - 1][1] + "1";
			return;
		}
	}

	return;
}

int main()
{
	int T;
	cin >> T;

	dp[1][0][0][0][0] = "00";
	dp[0][1][0][0][1] = "01";
	dp[0][0][1][0][0] = "10";
	dp[0][0][0][1][1] = "11";

	for (int tc = 1; tc <= T; tc++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		//끝자리가 0이거나 1인 복원 2진수를 찾는다
		fill_dp(a, b, c, d, 0);
		fill_dp(a, b, c, d, 1);

		cout << '#' << tc << ' ';
		
		//끝자리가 0이거나 1인 복원 2진수가 있다면 출력
		//없다면 impossible 출력
		if (dp[a][b][c][d][0].length() != 0)
		{
			cout << dp[a][b][c][d][0] << '\n';
		}
		else if (dp[a][b][c][d][1].length() != 0)
		{
			cout << dp[a][b][c][d][1] << '\n';
		}
		else
		{
			cout << "impossible\n";
		}
	}

	return 0;
}
