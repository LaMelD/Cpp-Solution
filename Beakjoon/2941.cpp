#include <iostream>
#include <string>

using namespace std;

int main()
{
	char s[105];
	cin.getline(s, sizeof(s), '\n');
	int i = 0;
	int cnt = 0;
	while (s[i] != 0)
	{
		switch (s[i])
		{
		case 'c':
			if (s[i + 1] == '=')
			{
				cnt++;
				i += 1;
			}
			else if (s[i + 1] == '-')
			{
				cnt++;
				i += 1;
			}
			else
			{
				cnt++;
			}
			break;
		case 'd':
			if (s[i + 1] == 'z')
			{
				if (s[i + 2] == '=')
				{
					cnt++;
					i += 2;
				}
				else
				{
					cnt++;
				}
			}
			else if (s[i + 1] == '-')
			{
				cnt++;
				i += 1;
			}
			else
			{
				cnt++;
			}
			break;
		case 'l':
			if (s[i + 1] == 'j')
			{
				cnt++;
				i += 1;
			}
			else
			{
				cnt++;
			}
			break;
		case 'n':
			if (s[i + 1] == 'j')
			{
				cnt++;
				i += 1;
			}
			else
			{
				cnt++;
			}
			break;
		case 's':
			if (s[i + 1] == '=')
			{
				cnt++;
				i += 1;
			}
			else
			{
				cnt++;
			}
			break;
		case 'z':
			if (s[i + 1] == '=')
			{
				cnt++;
				i += 1;
			}
			else
			{
				cnt++;
			}
			break;
		default:
			cnt++;
		}

		i++;
	}

	cout << cnt << endl;
}
