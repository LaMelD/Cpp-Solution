#include <string>
#include <vector>
#include <iostream>

using namespace std;

//문자열의 길이가 4또는 6이고 숫자로만 구성되어 있다면 true를 리턴
bool solution(string s) {
    if (s.length() == 4 || s.length() == 6){
        for (int i = 0; i < s.length(); i++){
            if (s[i] > '9') return false;
            if (s[i] < '0') return false;
        }
    }
    else return false;
    return true;
}
