#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> arr;
    int index = 0;
    while (index < commands.size()){
        arr.clear();
        
        for (int i = commands[index][0] - 1; i < commands[index][1]; i++){
            arr.push_back(array[i]);
        }
        
        //commands[idx][0]부터 commands[idx][1]까지를 arr에 저장하고
        //sort 한뒤 commands[idx][2] - 1위치에 있는 수를 answer에 push한다.
        sort(arr.begin(), arr.end());
        answer.push_back(arr[commands[index][2] - 1]);
        
        index++;
    }
    return answer;
}
