#include <string>
#include <vector>

using namespace std;

//문자열 배열읠 받아 "Kim"의 위치를 반환한다.
string solution(vector<string> seoul) {
    string answer = "김서방은 ";
    int position;
    for (int i = 0; i < seoul.size(); i++){
        if (seoul[i] == "Kim"){
            position = i;
            break;
        } 
    }
    string tmp = to_string(position);
    return answer + tmp + "에 있다";
}
