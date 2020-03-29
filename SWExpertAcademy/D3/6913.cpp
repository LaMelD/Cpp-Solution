#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		int N, M;
		cin >> N >> M;

		int first = 0;
		int max = 0;
		int input;

		for (int i = 0; i < N; i++)
		{
			int cnt = 0;

			for (int j = 0; j < M; j++)
			{
				cin >> input;
				if (input == 1)
				{
					cnt++;
				}
			}

			if (max < cnt)
			{
				max = cnt;
				first = 1;
			}
			else if (max == cnt)
			{
				first++;
			}
		}

		cout << '#' << tc << " ";
		cout << first << " " << max << endl;
	}

	return 0;
}
