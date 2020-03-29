#include <iostream>
#include <vector>
#include <string>

using namespace std;

int power(int a, int n)
{
	int ret = 1;

	for (int i = 0; i < n; i++)
	{
		ret = ret * a;
	}

	return ret;
}

int main()
{
	int T;
	cin >> T;

	int n;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> n;
		n = power(2, n);
		vector<int> strength;
		for (int i = 0; i < n; i++)
		{
			int input;
			cin >> input;
			strength.push_back(input);
		}

		int sum = 0;
		vector<int> winner;
		do
		{
			for (int i = 0; i < strength.size(); i += 2)
			{
				if (strength[i] < strength[i + 1])
				{
					winner.push_back(strength[i + 1]);
					sum += strength[i + 1] - strength[i];
				}
				else
				{
					winner.push_back(strength[i]);
					sum += strength[i] - strength[i + 1];
				}
			}
      
			strength.clear();
			strength = winner;
			winner.clear();
		} while (strength.size() != 1);

		cout << '#' << tc << ' ';
		cout << sum << endl;
	}
  
	return 0;
}
