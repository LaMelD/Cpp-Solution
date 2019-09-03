#include <string>
#include <vector>

using namespace std;

//시간복잡도 O(n)
int solution(string arrangement) {
    int answer = 0;
    int strlen = arrangement.length();
    int cnt = 0;
    
    for (int i = 0; i < strlen; i++){
        //arr[i] == '(' 이면 arr[i+1] == ')' 인지 확인한다
        //arr[i+1] == ')'이라면 cnt를 answer에 더한다
        //arr[i+1] != ')'이라면 cnt++ 한다
        if (arrangement[i] == '('){
            if (arrangement[i+1] == ')'){
                answer += cnt;
                i++;
            }
            else {
                cnt++;
            }
        }
        //arr[i] == ')' 라면 answer++하고
        //cnt-- 해준다
        else {
            answer++;
            cnt--;
        }
    }
    
    return answer;
}
