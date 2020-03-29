#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    int heightsize = heights.size();
    //모든 탑의 수신을 0으로 초기화
    vector<int> answer(heightsize);
    
    int send, recv;
    //뒤에서부터 탐색을 시작
    //i번째 탑보다 왼쪽에 있는 j번째 탑의 높이가 높다면
    //i번째 탑에서 보낸 신호를 수신할 수 있는 탑은 j번째 탑이다
    for (int i = heightsize - 1; i >= 0; i--){
        send = heights[i];
        for (int j = i - 1; j >= 0; j--){
            recv = heights[j];
            if (recv > send){
                answer[i] = j + 1;
                break;
            }
        }
    }
    
    return answer;
}
