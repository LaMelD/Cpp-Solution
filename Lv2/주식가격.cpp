#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    int first, second, cnt;
    int psize = prices.size();
    for (int i = 0; i < psize; i++){
        cnt = 0;
        first = prices[i];
        for (int j = i + 1; j < psize; j++){
            second = prices[j];
            //주식 가격이 떨어졌나
            if (first > second){
                cnt++;
                break;
            }
            else cnt++;
        }
        //주식가격이 유지된 시간을 answer에 push
        answer.push_back(cnt);
    }
    return answer;
}
