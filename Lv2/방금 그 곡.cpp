#include <algorithm>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct song
{
	int idx;
	int time;
	string name;
};

vector<string> split_string(string input, char on)
{
	vector<string> ret;

	string str = "";
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == on)
		{
			ret.push_back(str);
			str = "";
		}
		else
		{
			str += input[i];
		}
	}
	ret.push_back(str);

	return ret;
}

vector<int> stringscaletointscale(string input)
{
	vector<int> ret;
	for (int i = 0; i < input.length(); i++)
	{
		int tmp = 0;
		if (i == input.length() - 1)
		{
			switch (input[i])
			{
			case 'C':
				tmp = 1;
				break;
			case 'D':
				tmp = 3;
				break;
			case 'E':
				tmp = 5;
				break;
			case 'F':
				tmp = 6;
				break;
			case 'G':
				tmp = 8;
				break;
			case 'A':
				tmp = 10;
				break;
			case 'B':
				tmp = 12;
				break;
			}
		}
		else
		{
			switch (input[i])
			{
			case 'C' :
				if (input[i + 1] == '#')
				{
					tmp = 2;
					i++;
				}
				else
				{
					tmp = 1;
				}
				break;
			case 'D' :
				if (input[i + 1] == '#')
				{
					tmp = 4;
					i++;
				}
				else
				{
					tmp = 3;
				}
				break;
			case 'E' :
				tmp = 5;
				break;
			case 'F' :
				if (input[i + 1] == '#')
				{
					tmp = 7;
					i++;
				}
				else
				{
					tmp = 6;
				}
				break;
			case 'G' :
				if (input[i + 1] == '#')
				{
					tmp = 9;
					i++;
				}
				else
				{
					tmp = 8;
				}
				break;
			case 'A' :
				if (input[i + 1] == '#')
				{
					tmp = 11;
					i++;
				}
				else
				{
					tmp = 10;
				}
				break;
			case 'B' :
				tmp = 12;
				break;
			}
		}

		ret.push_back(tmp);
	}

	return ret;
}

int timetonum(string input)
{
	int H = (input[0] - '0') * 10 + (input[1] - '0');
	int M = (input[3] - '0') * 10 + (input[4] - '0');

	int ret = M + (H * 60);

	return ret;
}

string solution(string m, vector<string> musicinfos)
{
	string answer = "";

	vector<int> mscale = stringscaletointscale(m);
	int scalesize = mscale.size();
	vector<string> info;
	vector<song> select;
	for (int i = 0; i < musicinfos.size(); i++)
	{
		song input;
		info = split_string(musicinfos[i], ',');
		vector<int> infoscale = stringscaletointscale(info[3]);
		input.time = timetonum(info[1]) - timetonum(info[0]) + 1;
		input.idx = i;
		input.name = info[2];

		vector<int> scale;
		int k = 0;
		bool flag;
		for (int j = 0; j < input.time; j++)
		{
			scale.push_back(infoscale[k]);

			k++;
			k = k % infoscale.size();
		}

		if (scale.size() < scalesize)
		{
			continue;
		}

		for (int j = 0; j < (int)scale.size() - scalesize + 1; j++)
		{
			k = 0;
			flag = true;
			if (scale[j] == mscale[k])
			{
				int tmp = j;
				for (k = 0; k < scalesize; k++, tmp++)
				{
					if (scale[tmp] != mscale[k])
					{
						flag = false;
						break;
					}
				}
			}
			else
			{
				flag = false;
			}

			if (flag)
			{
				select.push_back(input);
				break;
			}
		}
	}

	if (select.size() == 0)
	{
		answer = "(None)";
	}
	else
	{
		sort(select.begin(), select.end(), [](song a, song b)
			{
				if (a.time == b.time)
				{
					return a.idx < b.idx;
				}
				return a.time > b.time;
			}
		);

		answer = select[0].name;
	}

	return answer;
}
