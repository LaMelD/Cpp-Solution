#include <string>
#include <vector>

using namespace std;

//n의 개수 만큼 "수"와 "박"을 반복한다
string solution(int n) {
    vector<string> subak = {"수","박"};
    string ans = "";
    for (int i = 0; i < n; i++){
        ans += subak[i % 2];
    }
    return ans;
}
