#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    if (s[0] == '+' || s[0] == '-'){
        string tmp = "";
        for (int i = 1; i < s.length(); i++){
            tmp += s[i];
        }
        answer = stoi(tmp);
        if (s[0] == '-') answer *= -1;
    }
    else {
        answer = stoi(s);
    }
    return answer;
}
