#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//sort함수에서 인스턴트 함수를 만들어 사용하는 방법
vector<string> solution(vector<string> strings, int n) {
    //sort에서 n을 사용하기위해 [n]을 넣었다
    sort(strings.begin(), strings.end(), [n](string a, string b){
        if (a[n] == b[n]){
            for (int i = 0; i < a.size(); i++){
                if (a[i] == b[i]) continue;
                else return a[i] < b[i];
            }
        }
        return a[n] < b[n];
    });
    
    return strings;
}

/////////////////////////////////////////////////////////////////

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//cmp함수를 만들어 sort에 적용하는 방법
int c;
bool cmp(string a, string b){
    if (a[c] == b[c]){
            for (int i = 0; i < a.size(); i++){
                if (a[i] == b[i]) continue;
                else return a[i] < b[i];
            }
        }
        return a[c] < b[c];
}

vector<string> solution(vector<string> strings, int n) {
    c = n;
    sort(strings.begin(), strings.end(), cmp);
    
    return strings;
}
