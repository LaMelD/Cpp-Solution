#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//Participant 배열과 completion 배열을 sort
//두 배열을 같이 검색하며 다른 부분이 나오면
//Participant[idx]를 리턴한다.

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for (int i = 0; i < 100000; i++){
        if (participant[i] != completion[i]) return participant[i];
    }
    return answer;
}
