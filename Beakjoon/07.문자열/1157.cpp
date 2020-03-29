#include <iostream>
#include <string>

using namespace std;

bool is_upper(char a)
{
	return 'A' <= a && a <= 'Z' ? true : false;
}

int main()
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);
	
	string s;
	cin >> s;
	int arr[26] = { 0, };

	for (int i = 0; i < s.length(); i++)
	{
		if (is_upper(s[i]))
		{
			arr[s[i] - 'A']++;
		}
		else
		{
			arr[s[i] - 'a']++;
		}
	}

	int count = 0;
	int max = 0;
	int m_idx = 0;
	for (int i = 0; i < 26; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
			m_idx = i;
			count = 1;
		}
		else if (max == arr[i])
		{
			count++;
		}
	}

	if (count == 1)
	{
		char ret = m_idx + 'A';
		cout << ret << endl;
	}
	else
	{
		cout << '?' << endl;
	}
}
