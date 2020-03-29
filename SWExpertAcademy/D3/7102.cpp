#include <iostream>
#include <vector>
#include <string>

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
		vector<int> num(N + M + 1);
		int max = 0;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				num[i + j]++;
				max = num[i + j] < max ? max : num[i + j];
			}
		}

		cout << '#' << tc << " ";
		for (int i = 0; i < num.size(); i++)
		{
			if (num[i] == max)
			{
				cout << i;
				if (i != num.size())
				{
					cout << " ";
				}
			}
		}
		cout << "\n";
	}
	return 0;
}
