#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int* dp_l;
int* dp_r;
int* A;

int max(int a, int b)
{
	return a < b ? b : a;
}

//11053번 문제를 앞에서 한번 뒤에서 한번 한다
int main() {
	int n;
	cin >> n;
	dp_l = new int[n + 2];
	dp_r = new int[n + 2];
	A = new int[n + 2];
	memset(dp_l, 0, sizeof(int) * (n + 2));
	memset(dp_r, 0, sizeof(int) * (n + 2));
	A[0] = 0;
	A[n + 1] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> A[i];
	}

	int k;
        //전방에서 한번
        for (int i = 1; i <= n; i++)
	{
		k = 0;
		for (int j = 0; j < i; j++)
		{
			if (A[j] < A[i])
			{
				if (dp_l[k] < dp_l[j])
				{
					k = j;
				}
			}
		}
		dp_l[i] = dp_l[k] + 1;
	}

        //후방에서 한번
	for (int i = n; i >= 1; i--)
	{
		k = n + 1;
		for (int j = n + 1; j > i; j--)
		{
			if (A[i] > A[j])
			{
				if (dp_r[k] < dp_r[j])
				{
					k = j;
				}
			}
		}
		dp_r[i] = dp_r[k] + 1;
	}

	delete[] A;
	A = new int[n + 2];

	int ans = 0;
        //전방 + 후방 - 1(중복) 의 최대값
	for (int i = 1; i <= n; i++)
	{
		A[i] = dp_l[i] + dp_r[i] - 1;
		ans = max(ans, A[i]);
	}

	cout << ans << endl;

	return 0;
}
