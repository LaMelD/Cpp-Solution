#include <iostream>
#include <string>

using namespace std;

char s[1000005];

bool is_upper(char a)
{
	return 'A' <= a && a <= 'Z' ? true : false;
}

int main()
{
	cin.getline(s, sizeof(s), '\n');
	
	int i = 0;
	bool flag = false;
	int ret = 0;
	while (1)
	{
		if (s[i] == 0) break;

		if (s[i] == ' ')
		{
			flag = false;
		}
		else
		{
			if (!flag)
			{
				flag = true;
				ret++;
			}
		}
		i++;
	}
	cout << ret << endl;
}
