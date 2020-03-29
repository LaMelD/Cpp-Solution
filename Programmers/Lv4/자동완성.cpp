#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

const int MaxC = 26;

int alphatoindex(const char alpha)
{
	return alpha - 'a';
}

class myTrie
{
private:
	vector<myTrie*> child;
	int matchCnt;
	bool Terminal;

private:
	void insert(const string&, const int);
	int find(const string&, const int);

public:
	myTrie();
	void insert(const string&);
	int find(const string&);
};
myTrie::myTrie()
{
	this->child = vector<myTrie*>(MaxC);
	this->matchCnt = 0;
	this->Terminal = false;
}
void myTrie::insert(const string& word)
{
	this->insert(word, 0);
	return;
}
void myTrie::insert(const string& word, int idx)
{
	this->matchCnt++;

	if (idx == word.length())
	{
		this->Terminal = true;
		return;
	}

	char alpha = word[idx];
	int childIndex = alphatoindex(alpha);
	if (this->child[childIndex] == NULL)
	{
		this->child[childIndex] = new myTrie();
	}

	this->child[childIndex]->insert(word, idx + 1);

	return;
}
int myTrie::find(const string& target)
{
	return this->find(target, 0);
}
int myTrie::find(const string& target, int idx)
{
	int ret = 0;

	if (idx == target.length())
	{
		return 0;
	}

	char alpha = target[idx];
	int childIndex = alphatoindex(alpha);
	if (this->child[childIndex]->matchCnt == 1)
	{
		return 1;
	}

	ret += this->child[childIndex]->find(target, idx + 1) + 1;

	return ret;
}

int solution(vector<string> words) 
{
	int answer = 0;

	myTrie root;

	for (int i = 0; i < words.size(); i++)
	{
		root.insert(words[i]);
	}

	for (int i = 0; i < words.size(); i++)
	{
		answer += root.find(words[i]);
	}

	return answer;
}
