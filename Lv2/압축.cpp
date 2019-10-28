#include <string>
#include <vector>

using namespace std;

string getsubstring(string input, int start, int end)
{
	string ret = "";
	for (int i = start; i <= end; i++)
	{
		ret += input[i];
	}
	return ret;
}

vector<int> solution(string msg)
{
	vector<string> diction = { "", "A", "B", "C", "D", "E", "F", "G", "H", "I" , "J" , "K" , "L" , "M" , "N" , "O" , "P" , "Q" , "R" , "S" , "T" , "U" , "V" , "W" , "X" , "Y", "Z" };

	vector<int> ans;
	int i = 0;
	int j = 0;
	int k;
	bool isin;
	string w;
	char c;
	while (1)
	{
		if (j == msg.length())
		{
			ans.push_back(k);
			break;
		}
		w = getsubstring(msg, i, j);

		isin = false;
		for (int tmpk = 1; tmpk < diction.size(); tmpk++)
		{
			if (diction[tmpk] == w)
			{
				k = tmpk;
				isin = true;
				break;
			}
		}

		if (!isin)
		{
			diction.push_back(w);
			i = j;

			ans.push_back(k);
			continue;
		}

		j++;
	}

	return ans;
}
