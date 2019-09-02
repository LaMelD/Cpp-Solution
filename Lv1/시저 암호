#include <string>
#include <vector>

using namespace std;

//ascii 에서 대문자 < 소문자
string solution(string s, int n) {
    string answer = "";
    
    for (int i = 0; i < s.size(); i++){
        //공백 판별
        if (s[i] == ' ') continue;
        //소문자 판별
        if (s[i] >= 'a'){ 
            if (s[i] + n > 'z')
                s[i] = s[i] + n - 'z' + 'a' - 1;
            else s[i] += n;
        }
        //대문자 판별
        else if (s[i] >= 'A'){
            if (s[i] + n > 'Z')
                s[i] = s[i] + n - 'Z' + 'A' - 1;
            else s[i] += n;
        }
    }
    
    return s;
}
