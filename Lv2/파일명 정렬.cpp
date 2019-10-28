#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class File
{
private :
	int idx;
	string head;
	string head_upper;
	string number;
	int num;
	string tail;
public :
	File(int, string);
	string getoriginal();
	friend bool operator<(File, File);
};
File::File(int idx, string input)
{
	this->idx = idx;
	int i = 0;
	int cnt = 0;
	this->head = "";
	this->head_upper = "";
	while (1)
	{
		if ('0' <= input[i] && input[i] <= '9')
		{
			break;
		}
		this->head += input[i];
		this->head_upper += toupper(input[i++]);
	}

	this->number = "";
	while (cnt < 5)
	{
		if (i == input.length())
		{
			break;
		}

		if ('0' <= input[i] && input[i] <= '9')
		{
			this->number += input[i++];
			cnt++;
		}
		else
		{
			break;
		}
	}
	this->num = stoi(this->number);

	this->tail = "";
	if (i != input.length())
	{
		for (; i < input.length(); i++)
		{
			this->tail += input[i];
		}
	}
}
string File::getoriginal()
{
	string ret = this->head;
	ret += this->number;
	ret += this->tail;

	return ret;
}
bool operator<(File a, File b)
{
	if (a.head_upper == b.head_upper)
	{
		if (a.num == b.num)
		{
			return a.idx < b.idx;
		}
		return a.num < b.num;
	}
	return a.head_upper < b.head_upper;
}

vector<string> solution(vector<string> files)
{
	vector<string> answer;

	vector<File> w;

	for (int i = 0; i < files.size(); i++)
	{
		File input(i, files[i]);
		w.push_back(input);
	}

	sort(w.begin(), w.end());

	for (int i = 0; i < w.size(); i++)
	{
		answer.push_back(w[i].getoriginal());
	}

	return answer;
}
