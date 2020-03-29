#include <iostream>

using namespace std;

int max(int a, int b)
{
	return a < b ? b : a;
}

int main(int argc, char** argv)
{
	//입출력 가속
	cin.tie(NULL);
	cout.sync_with_stdio(false);

	int test_case;
	int T;
	cin >> T;
	int n;
	int nv;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;
		cin >> nv;
		int result = nv;
		for (int i = 1; i < n; i++)
		{
			cin >> nv;
			result = max(result + nv, result * nv);
		}
		cout << '#' << test_case << " " << result << "\n";
	}
	return 0;
}
