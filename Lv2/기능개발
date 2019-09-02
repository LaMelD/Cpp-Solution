#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> date;
    int i, j, cnt;
    int p_size = progresses.size();
    int cnt;
    
    //각 기능들의 완성까지 남은 기간을 date배열에 저장한다
    for (i = 0; i < p_size; i++){
        int rest = 100 - progresses[i];
        cnt = 1;
        while (rest > (cnt * speeds[i])){
            cnt++;
        }
        date.push_back(cnt);
    }
    
    //이전 기능의 완성까지 남은 기간과 다음 기능의 완성까지 남은 기간을 비교한다
    i = 0; j = 1; cnt = 1;
    while (i < p_size && j < p_size){
        //다음 기능의 완성까지 남은 기간이 길다면
        //현재까지 완성 가능한 기능을 answer에 push하고
        //이전 기능을 다음 기능으로 교체한다
        if (date[i] < date[j]){
            i = j;
            j++;
            answer.push_back(cnt);
            cnt = 1;
        }
        else {
            j++;
            cnt++;
        }
    }
    //마지막 push가 안된 것을 push한다
    answer.push_back(cnt);
    
    return answer;
}
