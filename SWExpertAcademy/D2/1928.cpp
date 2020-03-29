#include <iostream>
#include <string>.
#include <vector>

using namespace std;

int main()
{
	int  T;
	cin >> T;

	string chart = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	for (int tc = 1; tc <= T; tc++)
	{
		string input;
		cin >> input;

		char ch;
		unsigned int a;
		string result;
		for (int i = 0; i < input.length(); i += 4)
		{
			a = 0;
			for (int j = 0; j < 4; j++)
			{
				a = a << 6;
				ch = input[i + j];
				int k;
				for (k = 0; k < chart.length(); k++)
				{
					if (chart[k] == ch)
					{
						break;
					}
				}
				a += (unsigned int)k;
			}
			unsigned int first, second, third;
			first = a >> 16;
			second = (a >> 8) - (first << 8);
			third = a - (first << 16) - (second << 8);

			result += first;
			result += second;
			result += third;
		}
		
		cout << '#' << tc << ' ';
		cout << result << '\n';
	}

	return 0;
}
