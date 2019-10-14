#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
	vector<string> ret;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		vector<int> tmp(n, 0);
		for (int j = 0; j < n; j++)
		{
			a = arr1[i] % 2;
			b = arr2[i] % 2;
			arr1[i] = arr1[i] >> 1;
			arr2[i] = arr2[i] >> 1;

			if (a == 1 || b == 1)
			{
				tmp[n - 1 - j] = 1;
			}
		}

		string s = "";
		for (int j = 0; j < n; j++)
		{
			if (tmp[j] == 1)
			{
				s += '#';
			}
			else
			{
				s += ' ';
			}
		}
		ret.push_back(s);
	}

	return ret;
}
