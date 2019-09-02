#include <string>
#include <iostream>
using namespace std;

bool solution(string s){
    bool answer = true;
    
    int np = 0;
    int ny = 0;
    for (int i = 0; i < s.length(); i++){
        switch (s[i]){
            case 'p' :
            case 'P' : np++;
                break;
            case 'y' :
            case 'Y' : ny++;
                break;
            default:;
        }
    }
    
    //p의 수와 y의 수가 다르면 false
    if (np != ny) return false;
    
    return answer;
}
