#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}

int solution(vector<int> v)
{
	sort(v.begin(), v.end());
	int ret = v.front() + v.back() + v.size();
	for (int i = 0; i < v.size() - 1; i++)
	{
		ret += max(v[i], v[i + 1]);
	}

	return ret;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;
		vector<int> nv;
		for (int i = 0; i < n; i++)
		{
			int ni;
			cin >> ni;
			nv.push_back(ni);
		}
		cout << '#' << test_case << " ";
		cout << solution(nv) << endl;
	}
	return 0;
}
