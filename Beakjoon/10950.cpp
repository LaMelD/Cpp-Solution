#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int T;
	cin >> T;
	int a, b;
	vector<int> V;
	for (int tc = 0; tc < T; tc++)
	{
		cin >> a >> b;
		V.push_back(a + b);
	}
	for (int i = 0; i < V.size(); i++)
	{
		cout << V[i] << endl;
	}
}
