#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int ssize = s.length();
    if (ssize % 2 == 0){
        answer += s[ssize/2 - 1];
        answer += s[ssize/2];
    }
    else {
        answer = s[ssize/2];
    }
    return answer;
}
