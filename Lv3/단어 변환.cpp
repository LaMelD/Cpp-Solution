#include <string>
#include <vector>
#include <iostream>

using namespace std;

int word_size;
int ans;

bool Check(string v, string b)
{
	int dif = 0;
	int len = v.length();
    
	for (int i = 0; i < len; i++)
    {
		if (v[i] != b[i]) dif++;
        
		if (dif > 1) return false;
	}
    
	return true;
}

void DFS(string b, string t, vector<string> vec, int *visit, int idx)
{
	idx++;
    
	if (idx > word_size + 1) return;
    
	if (Check(b, t) && idx < ans)
    {
		ans = idx;
		return;
	}
    
	for (int i = 0; i < word_size; i++)
    {
		if (Check(vec[i], b) && visit[i] == 0)
        {
			visit[i] = 1;
			DFS(vec[i], t, vec, visit, idx);
			visit[i] = 0;
		}
	}
}

int solution(string begin, string target, vector<string> words) 
{
	int answer = 0;
	word_size = words.size();
	ans = word_size + 1;
    
	int *visit = new int[word_size];
    
	int i;
	bool isin = false;
    
	for (i = 0; i < word_size; i++)
    {
		visit[i] = 0;
		if (words[i] == target) isin = true;
	}

	if (!isin) return 0;
	
	DFS(begin, target, words, visit, 0);

	return answer = ans;
}
