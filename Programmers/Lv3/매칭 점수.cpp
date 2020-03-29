#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//알파벳인지 판별
bool is_alpha(char a)
{
	if ('a' <= a && a <= 'z')
	{
		return true;
	}

	if ('A' <= a && a <= 'Z')
	{
		return true;
	}

	return false;
}

//문자 '<'과 '>'을 기준으로 
vector<string> split_by_Opne_Close(string input)
{
	vector<string> ret;

	string tmp = "";
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == '<')
		{
			if (tmp != "\n" && tmp.length() != 0)
			{
				ret.push_back(tmp);
			}
			tmp = "<";
		}
		else if (input[i] == '>')
		{
			tmp += input[i];
			ret.push_back(tmp);
			tmp = "";
		}
		else
		{
			tmp += input[i];
		}
	}

	return ret;
}

//알파벳이 아닌 문자열을 만나면 스플릿한다
//모든 알파벳을 소문자로 만들어준다
vector<string> split_not_alphabet(string input)
{
	vector<string> ret;

	string tmp = "";
	for (int i = 0; i < input.length(); i++)
	{
		if (is_alpha(input[i]))
		{
			tmp += tolower(input[i]);
		}
		else
		{
			if (tmp.length() != 0)
			{
				ret.push_back(tmp);
				tmp = "";
			}
		}
	}

	return ret;
}

class Page
{
private :
	int idx;	//몇번째 인풋인지
	double itlinkscore;	//현재 페이지의 (기본점수 / 링크수)
	double matchingscore;	//현재 페이지의 매칭 스코어
	string url;	//현재 페이지의 URL
	vector<string> link;	//링크 url정보
public :
	Page(int idx, string word, string input);
	string getUrl() { return this->url; }
	double getItLinkScore() { return this->itlinkscore; }
	void addMatchingScore(double itlinkscore) { this->matchingscore += itlinkscore; }
	double getMatchinScore() { return this->matchingscore; }
	int getIdx() { return this->idx; }
	vector<string> getLink() { return this->link; }
};
Page::Page(int idx, string word, string input)
{
	this->idx = idx;
	this->url = "";
	vector<string> info = split_by_Opne_Close(input);
	int i = 0;
	//url을 찾는다 -- i 값은 다음에도 이용된다
	//<meta 를 찾는다 size가 27개 보다 많을 경우 체크한다
	while (1)
	{
		if (27 < info[i].length())
		{
			//시작이 <meta이고
			if (info[i][0] == '<' && info[i][1] == 'm' && info[i][2] == 'e' && info[i][3] == 't' && info[i][4] == 'a')
			{
				int j;
				//중간에 content가 있다면
				for (j = 5; j < info[i].length(); j++)
				{
                                        //  문자열 :: content="https://
                                        //포함하고 있는지 판단하여 url를 입력한다
					if (info[i][j] == 'c' && info[i][j + 1] == 'o' && info[i][j + 2] == 'n' && info[i][j + 3] == 't' && info[i][j + 4] == 'e' && info[i][j + 5] == 'n' && info[i][j + 6] == 't' && info[i][j + 7] == '=' && info[i][j + 8] == '\"' && info[i][j + 9] == 'h' && info[i][j + 10] == 't' && info[i][j + 11] == 't' && info[i][j + 12] == 'p' && info[i][j + 13] == 's' && info[i][j + 14] == ':' && info[i][j + 15] == '/' && info[i][j + 16] == '/')
					{
						for (int k = j + 17; info[i].length(); k++)
						{
							if (info[i][k] == '\"')
							{
								break;
							}
							this->url += info[i][k];
						}
						break;
					}
				}

				if (this->url.length() != 0)
				{
					break;
				}
			}
		}
		i++;
	}
	
	for (i++; i < info.size(); i++)
	{
                //  문자열 :: <a href="https://
                //포함하고 있는지 판단하여 tmp에 입력하고 link에 푸시한다
		if (info[i][0] == '<' && info[i][1] == 'a' && info[i][2] == ' ' && info[i][3] == 'h' && info[i][4] == 'r' && info[i][5] == 'e' && info[i][6] == 'f' && info[i][7] == '=' && info[i][8] == '\"' && info[i][9] == 'h' && info[i][10] == 't' && info[i][11] == 't' && info[i][12] == 'p' && info[i][13] == 's' && info[i][14] == ':' && info[i][15] == '/' && info[i][16] == '/')
		{
			string tmp = "";
			for (int j = 17; j < info[i].length(); j++)
			{
				if (info[i][j] == '\"')
				{
					break;
				}
				tmp += info[i][j];
			}

			this->link.push_back(tmp);
		}
	}

	int numberoflink = this->link.size();

        //input을 새롭게 파싱한다
	info = split_not_alphabet(input);
	int score = 0;
        //파싱한 문자열 배열에서 word와 같은 것이 있는지 확인하여 스코어를 올린다
	for (i = 0; i < info.size(); i++)
	{
		if (word == info[i])
		{
			score++;
		}
	}

        //matchingscore를 기본점수로 초기화 하고
        //다른 곳에 전해줄 (기본점수 / 링크 수)를 초기화
	this->matchingscore = score;
	this->itlinkscore = (double)score / (double)numberoflink;
}

int solution(string word, vector<string> pages) 
{
	vector<Page> parsing_pages;
	for (int i = 0; i < word.length(); i++)
	{
		word[i] = tolower(word[i]);
	}
	
	for (int i = 0; i < pages.size(); i++)
	{
		Page page(i, word, pages[i]);
		parsing_pages.push_back(page);
	}

	for (int i = 0; i < pages.size(); i++)
	{
		vector<string> tmpLink = parsing_pages[i].getLink();
		for (int j = 0; j < tmpLink.size(); j++)
		{
			for (int k = 0; k < pages.size(); k++)
			{
				if (tmpLink[j] == parsing_pages[k].getUrl())
				{
					parsing_pages[k].addMatchingScore(parsing_pages[i].getItLinkScore());
				}
			}
		}
	}

	sort(parsing_pages.begin(), parsing_pages.end(), [](Page a, Page b) 
		{
			if (a.getMatchinScore() == b.getMatchinScore())
			{
				return a.getIdx() < b.getIdx();
			}
			return b.getMatchinScore() < a.getMatchinScore();
		}
	);

	return parsing_pages.front().getIdx();
}
