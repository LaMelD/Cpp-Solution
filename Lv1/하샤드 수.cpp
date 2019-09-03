#include <string>
#include <vector>

using namespace std;

//자리수 더하기
int sum(int n){
    int ret = 0;
    while (n){
        ret += n % 10;
        n = n / 10;
    }
    return ret;
}

bool solution(int x) {
    bool answer = false;
    int n = sum(x);
    if (x % n == 0) answer = true;
    return answer;
}
