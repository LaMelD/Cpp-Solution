#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//대문자인가
bool is_upper(char a)
{
	if (a >= 'A' && a <= 'Z') return true;
	return false;
}

//소문자인가
bool is_lower(char a)
{
	if(a >= 'a' && a <= 'z') return true;
	return false;
}

vector<int> solution(int n, vector<string> s)
{
	vector<int> ret;

	for (int i = 0; i < n; i++)
	{
                //단어의 첫 문자인지 판별
		bool is_firstchar = true;
                //Name의 조건을 만족했는지 판별
		bool is_name = true;
                //Name의 개수
		int name_cnt = 0;
		for (int j = 0; j < s[i].length(); j++)
		{
                        //공백을 만나면 지금 받아온 단어가 Name이었는지 확인
			if (s[i][j] == ' ')
			{
				if (is_name) name_cnt++;
                                //공백 다음이 다음 문자의 첫 문자이기 때문에 true
				is_firstchar = true;
                                //is_name 초기화
				is_name = true;
				continue;
			}
                        
                        //구두점을 만나면 바로 이전의 단어가 Name이었는지 확인
			if (j == s[i].length() - 1)
			{
				if (is_name) name_cnt++;
				break;
			}

                        //첫번째 문자인가
			if (is_firstchar)
			{
                                //첫번째 문자이고 대문자인가
				if (!is_upper(s[i][j]))
				{
                                        //대문자가 아니라면
					is_name = false;
				}
			}
                        //단어의 첫번째가 아닌 문자
			else
			{
                                //is_name플레그 확인
				if (is_name)
				{
                                        //Name이라면 단어의 첫번재를 제외한 모든 문자가
                                        //소문자로 구성되어 있어야 하므로
                                        //소문자인지 판별
					if (!is_lower(s[i][j]))
					{
                                                //소문자가 아니라면 false
						is_name = false;
					}
				}
			}
                        //첫번째 단어를 지나왔으므로 다음 단어로 넘어가기 전까지 false로 유지
			is_firstchar = false;
		}
                //한 문장을 확인 후 이름의 개수를 ret에 push
		ret.push_back(name_cnt);
	}

	return ret;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;
                
                //문장 단위로 s에 저장
		vector<string> s;
                
		for (int i = 0; i < n; i++)
		{
			string str = "";
                        //문장 단위로 자르기
			while (1)
			{
				string tmp;
				cin >> tmp;
				if (tmp.back() == '?' || tmp.back() == '.' || tmp.back() == '!')
				{
					str += tmp;
					break;
				}
				str += tmp;
				str += " ";
			}
			s.push_back(str);
		}
                
		cout << '#' << test_case << " ";
                
		vector<int> ans = solution(n, s);
                
		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
