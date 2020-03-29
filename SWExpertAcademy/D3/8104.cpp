#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) 
	{
		int n, k;
		cin >> n >> k;
		vector<int> w(k);
		//반복횟수
		int cnt1 = 0;
		//학생의 등수
		int cnt2 = 1;
		while (1) 
		{
			//순서대로
			if (cnt1 < n) 
			{
				for (int i = 0; i < k; i++) 
				{
					w[i] += cnt2;
					cnt2++;
				}
				cnt1++;
			}
			else break;

			//역순으로
			if (cnt1 < n) 
			{
				for (int i = k - 1; i > -1; i--) 
				{
					w[i] += cnt2;
					cnt2++;
				}
				cnt1++;
			}
			else break;
		}

		cout << "#" << test_case << " ";
		for (int i = 0; i < k; i++) 
		{
			cout << w[i];
			if (i != k - 1) cout << " ";
		}
		cout << endl;
	}
	return 0;
}
