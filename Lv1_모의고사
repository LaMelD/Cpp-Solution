#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int answers_size = answers.size();
    vector<int> s1 = {1, 2, 3, 4, 5};                 // 1번 선수의 찍는 방법, size 5
    vector<int> s2 = {2, 1, 2, 3, 2, 4, 2, 5};        // 2번 선수의 찍는 방법, size 8
    vector<int> s3 = {3, 3 ,1, 1, 2, 2, 4, 4, 5, 5};  // 3번 선수의 찍는 방법, size 10
    int score[3] = {0, 0, 0};
    
    for (int i = 0; i < answers_size; i++){
        if (answers[i] == s1[i % s1.size()]){
            score[0]++;
        }
        if (answers[i] == s2[i % s2.size()]) {
            score[1]++;
        }
        if (answers[i] == s3[i % s3.size()]) {
            score[2]++;
        }
    }
    
    int max = 0;
    for (int i = 0; i < 3; i++){
        if ( max < score[i]) max = score[i];
    }
    
    for (int i = 0; i < 3; i++){
        if (max == score[i]) answer.push_back(i+1);
    }
    
    return answer;
}
