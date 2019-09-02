#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int n) {
    vector<int> v;
    
    //124나라의 숫자 규칙
    //3진수라는 가정으로 접근하여
    //규칙을 찾는다
    int a = 0;
    while (n){
        n = n - 1;
        a = n % 3;
        n = n / 3;
        v.push_back(a);
    }
    
    string ans = "";
    for (int i = v.size() - 1; i > -1; i--){
        if (v[i] == 0)
            ans += '1';
        else if (v[i] == 1)
            ans += '2';
        else 
            ans += '4';
    }
    
    return ans;
}
