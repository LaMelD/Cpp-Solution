#include <string>
#include <vector>

using namespace std;

//소수에 관련된 문제는
//에라토스테네스의 체를 활용한다

int solution(int n) {
    int answer = 0;
    vector<bool> prime(n+1);
    for (int i = 0; i < prime.size(); i++) prime[i] = true;
    
    int tmp;
    for (int i = 2; i < n + 1; i++){
        tmp = 2;
        if (prime[i]){
            while (tmp * i <= n){
                prime[i * tmp] = false;
                tmp++;
            }
            answer++;
        }
    }
    return answer;
}
