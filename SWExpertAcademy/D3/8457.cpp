#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	//입출력 가속
	cin.tie(NULL);
	cout.sync_with_stdio(false);

	int test_case;
	int T;
	cin >> T;
	int n, b, e;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n >> b >> e;
		int cnt = 0;
		for (int i = 0; i < n; i++) 
		{
			int nv;
			cin >> nv;
			int tmp = nv;
			while (1)
			{
				if (b - e <= tmp && tmp <= b + e)
				{
					cnt++;
					break;
				}
				else if (tmp > b - e)
				{
					break;
				}
				tmp += nv;
			}
		}
		cout << '#' << test_case << " " << cnt << "\n";
	}
	return 0;
}
