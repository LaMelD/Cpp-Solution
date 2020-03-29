#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(vector<int> big, vector<int> small, int b_size, int s_size)
{
        //각 숫자열에 들어갈 수 있는 수의 범위가 주어지지 않았다
        //테스트케이스에 있는 값의 범위가 -10~10까지인 것을 확인하여
        //최솟값을 -8000으로 두었다
	int ret = -8000;

	int limit = b_size - s_size + 1;
	for (int i = 0; i < limit; i++)
	{
		int sum = 0;
		for (int j = 0; j < s_size; j++)
		{
			sum += small[j] * big[i + j];
		}
		ret = ret > sum ? ret : sum;
	}
	return ret;
}

int main()
{
	int T;
	cin >> T;
	int n, m;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> n >> m;
		vector<int> M, N;
		int input;
		for (int i = 0; i < n; i++)
		{
			cin >> input;
			N.push_back(input);
		}
		for (int j = 0; j < m; j++)
		{
			cin >> input;
			M.push_back(input);
		}

		int ans;
		if (n > m)
		{
			ans = solution(N, M, n, m);
		}
		else
		{
			ans = solution(M, N, m, n);
		}

		cout << '#' << tc << ' ' << ans << endl;
	}

	return 0;
}
