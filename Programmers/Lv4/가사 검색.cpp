#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

const int Max_Trie_Children = 26;
const int Max_Word_Size = 10001;

int alphatoindex(const char alpha)
{
	return alpha - 'a';
}

bool IsWildCard(const char alpha)
{
	return alpha == '?';
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
	this->child = vector<myTrie*>(Max_Trie_Children);
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
	if (idx == target.length())
	{
		if (this->Terminal)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	char alpha = target[idx];
	if (IsWildCard(alpha))
	{
		return this->matchCnt;
	}

	int childIndex = alphatoindex(alpha);
	if (this->child[childIndex] == NULL)
	{
		return 0;
	}

	return this->child[childIndex]->find(target, idx + 1);
}

class LyricS
{
private:
	vector<myTrie> trie;
	vector<myTrie> reversetrie;

public:
	LyricS();
	void insert(string);
	int find(string);
};
LyricS::LyricS()
{
	this->trie = vector<myTrie>(Max_Word_Size);
	this->reversetrie = vector<myTrie>(Max_Word_Size);
}
void LyricS::insert(string word)
{
	this->trie[word.length()].insert(word);
	reverse(word.begin(), word.end());
	this->reversetrie[word.length()].insert(word);
}
int LyricS::find(string target)
{
	if (target[0] == '?')
	{
		reverse(target.begin(), target.end());
		return this->reversetrie[target.length()].find(target);
	}
	else
	{
		return this->trie[target.length()].find(target);
	}
}

vector<int> solution(vector<string> words, vector<string> queries)
{
	vector<int> ans(queries.size(), 0);

	LyricS root;

	for (int i = 0; i < words.size(); i++)
	{
		root.insert(words[i]);
	}

	for (int i = 0; i < queries.size(); i++)
	{
		ans[i] = root.find(queries[i]);
	}

	return ans;
}
