#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words)
{
	vector<int> answer;
	string tmp = words[0];
	int i;
	bool chk = false;
	for (i = 1; i < words.size(); i++)
	{
		//이전 단어의 끝과 현재 단어의 처음이 일치하는가
		if (tmp[tmp.length() - 1] == words[i][0])
		{
			tmp = words[i];
		}
		else
		{
			chk = true;
			break;
		}

		for (int j = 0; j < i; j++)
		{
			//이전에 사용한 단어인가
			if (words[i] == words[j])
			{
				chk = true;
			}
		}

		if (chk) break;
	}

	if (chk) 
	{
		//몇번 사람이
		answer.push_back((i % n) + 1);
		//몇번째 차례에서 실패했는가
		answer.push_back((i / n) + 1);
		return answer;
	}

	return { 0, 0 };
}
