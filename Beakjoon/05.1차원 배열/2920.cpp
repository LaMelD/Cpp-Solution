#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	vector<int> v;
	for (int i = 0; i < 8; i++)
	{
		cin >> n;
		v.push_back(n);
	}

	bool is_asc = true;
	bool is_desc = true;
	for (int i = 0; i < 8; i++)
	{
		if (v[0] == 1)
		{
			if (v[i] != 1 + i) is_asc = false;
		}
		else is_asc = false;
		if (v[0] == 8)
		{
			if (v[i] != 8 - i) is_desc = false;
		}
		else is_desc = false;
	}
	if (is_asc) cout << "ascending\n";
	else if (is_desc) cout << "descending\n";
	else cout << "mixed\n";
}
