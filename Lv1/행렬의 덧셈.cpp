#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int asize = arr1.size();
    int a0size = arr1[0].size();
    for (int i = 0; i < asize; i++){
        for (int j = 0; j < a0size; j++){
            arr1[i][j] += arr2[i][j];
        }
    }
    return arr1;
}
