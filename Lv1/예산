//2018 서머코딩
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    
    //d를 오름차순으로 정렬
    sort(d.begin(), d.end());
    int sum = 0;
    for (int i = 0; i < d.size(); i++){
        //작은 d 부터 sum에 더해준다
        sum += d[i];
        //budget을 넘으면 answer++하지 않고 break
        if (sum > budget){
            break;
        }
        answer++;
    }
    return answer;
}
