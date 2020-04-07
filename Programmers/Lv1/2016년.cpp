//2016년
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int a, int b) {
    vector<string> answer = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    int cnt = 0;
    switch(a){
        case 12 : cnt += 30;
        case 11 : cnt += 31;
        case 10 : cnt += 30;
        case 9 : cnt += 31;
        case 8 : cnt += 31;
        case 7 : cnt += 30;
        case 6 : cnt += 31;
        case 5 : cnt += 30;
        case 4 : cnt += 31;
        case 3 : cnt += 29;
        case 2 : cnt += 31;
        case 1 : cnt += 0;
    }
    cnt = cnt + b - 1;
    
    return answer[cnt % 7];
}
