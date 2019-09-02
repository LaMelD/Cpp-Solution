#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    if (arr.size() == 1) return { -1 };
    int mini = arr[0];
    int mini_idx = 0;
    for (int i = 1; i < arr.size(); i++){
        if (arr[i] < mini){
            mini = arr[i];
            mini_idx = i;
        }
    }
    //vector::erase 사용법
    arr.erase(arr.begin() + mini_idx);
    return arr;
}
