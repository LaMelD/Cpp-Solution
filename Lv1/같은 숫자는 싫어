#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    //연속적으로 같은 수가 나오면 
    num = arr[0];
    answer.push_back(arr[0]);
    for (int i = 1; i < arr.size(); i++){
        if (num == arr[i]) continue;
        else {
            num = arr[i];
            answer.push_back(arr[i]);
        }
    }
    return answer;
}
