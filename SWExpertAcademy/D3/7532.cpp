#include <iostream>

using namespace std;

int solution(int S, int E, int M)
{
	while (1)
	{
		if (S == E)
		{
			if (E == M)
			{
				return S;
			}
			else if (E > M)
			{
				M += 29;
			}
			else
			{
				E += 24;
			}
		}
		else if (S > E)
		{
			E += 24;
		}
		else
		{
			S += 365;
		}
	}
}

int main()
{
	//입출력 가속
	cin.tie(NULL);
	cout.sync_with_stdio(false);

	int T;
	cin >> T;
	string s;
	for (int tc = 1; tc <= T; tc++)
	{
		int S, E, M;
		cin >> S >> E >> M;
		
		cout << '#' << tc << " ";
		cout << solution(S, E, M) << '\n';
	}

	return 0;
}
