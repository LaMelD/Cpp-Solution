#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	int a, b;
	vector<int> v;
	for (int tc = 0; tc < T; tc++)
	{
		cin >> a >> b;
		v.push_back(a + b);
	}
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "\n";
	}
}
