#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    vector<int> arr(n);
    int tmp1 = 0;
    int tmp2 = 0;
    
    //lost, reserve를 sort한다
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    //arr를 초기화 한다
    //초기값은 1
    //잃어버린 사람은 -1
    //여벌이 있는 사람은 +1
    for (int i = 0; i < n; i++){
        arr[i] = 1;
        if (i == lost[tmp1] - 1){
            arr[i]--;
            tmp1++;
        }
        if ( i == reserve[tmp2] - 1){
            arr[i]++;
            tmp2++;
        }
    }
    
    //0번째 사람이 여벌을 갖고 있고
    //1번째 사람이 여벌이 없고 잊어버렸다면
    //0번째 사람이 1번째 사람에게 체육복을 빌려준다
    if (arr[0] == 2 && arr[1] == 0){
        arr[0]--;
        arr[1]++;
    }
    for (int i = 1; i < n; i++){
        //i번째 사람이 여벌이 있다면
        if (arr[i] == 2){
            //i - 1번째 사람이 여벌이 없고 잃어버렸다면
            if (arr[i - 1] == 0){
                arr[i - 1]++;
                arr[i]--;
            }
            //i + 1번째 사람이 여벌이 없고 잃어버렸다면
            else if (arr[i + 1] == 0){
                arr[i + 1]++;
                arr[i]--;
            }
        }
    }
    
    //마지막으로 갖은 체육복이 없다면 answer--해준다.
    for (int i = 0; i < n; i++) 
        if (arr [i] == 0) answer--;
    
    return answer;
}
