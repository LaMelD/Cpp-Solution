#include <string>

using namespace std;

int solution(string s)
{
	//stack에 0번째 문자를 넣어놓는다.
	string stack = "";
	stack += s[0];
	
	for (int i = 1; i < s.size(); i++)
	{
		//stack의 마지막 문자가 현재 문자와 같은가
		if (stack.back() == s[i])
			//stack을 pop_back해준다
			stack.pop_back();
		else
			//다르다면 stack뒤에 추가해준다
			stack.push_back(s[i]);
	}

	//문자열의 크기가 0이면 1리턴
	if (stack.size() == 0) return 1;

	return 0;
}
