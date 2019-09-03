#include <iostream>

using namespace std;

long long solution(long long n) {
    //n에 루트를 씌운다 :: sqrt함수
    long long tmp = sqrt(n);
    if(tmp * tmp == n){
        return (tmp + 1) * (tmp + 1);
    }
    return -1;
}
