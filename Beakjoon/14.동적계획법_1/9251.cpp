#include <iostream>
#include <string>
#include <vector>

using namespace std;
int max(int a, int b)
{
	return a < b ? b : a;
}

int LCS(string, string);

int main() {
	string A, B;

	cin >> A >> B;

	int ans = LCS(A, B);

	cout << ans << endl;

	return 0;
}

//알려져있는 LCS 알고리즘을 사용했다
int LCS(string A, string B)
{
	int ret = 0;
	int Asize = A.length();
	int Bsize = B.length();
	vector<vector<int>> lcs(Asize + 1, vector<int>(Bsize + 1, 0));

	for (int i = 1; i <= Asize; i++)
	{
		for (int j = 1; j <= Bsize; j++)
		{
			if (A[i - 1] == B[j - 1])
			{
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else
			{
				lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
			}
		}
	}
        
	ret = lcs[Asize][Bsize];

	return ret;
}
