#include <string>
#include <vector>

using namespace std;

//try hello world -> TrY HeLlO WoRlD
string solution(string s) {
    string answer = "";
    
    //공백을 기준으로 문자열을 쪼갠다
    vector<string> stack;
    string tmp = "";
    for (int i = 0; i < s.length(); i++){
        if (s[i] == ' '){
            stack.push_back(tmp);
            tmp = "";
            continue;
        }
        tmp += s[i];
    }
    stack.push_back(tmp);
    
    //쪼개진 문자열을 하나씩 판별한다
    for (int i = 0; i < stack.size(); i++){
        for (int j = 0; j < stack[i].length(); j++){
            //짝수번째 일 때
            if (j % 2 == 0){
                //문자가 소문자일 경우
                if (stack[i][j] > 'Z'){
                    stack[i][j] = stack[i][j] - 'a' + 'A';
                }
                //문자가 대문자일 경우 바꾸지 않는다
            }
            //홀수번째 일 때
            else {
                //문자가 대문자일 경우
                if (stack[i][j] < 'a'){
                    stack[i][j] = stack[i][j] - 'A' + 'a';
                }
                //문자가 소문자라면 바꾸지 않는다
            }
        }
    }
    
    for (int i = 0; i < stack.size(); i++){
        answer += stack[i];
        //마지막 문자열인 경우 문자열을 answer에 더하고 공백을 추가하지 않는다
        if (i == stack.size() - 1) break;
        answer += " ";
    }
    
    return answer;
}
