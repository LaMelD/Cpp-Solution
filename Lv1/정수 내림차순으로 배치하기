#include <string>
#include <vector>
#include <functional>		//greater와 less 사용가능
#include <algorithm>

using namespace std;

//sort를 사용한 방법
long long solution(long long n) {
    long long answer = 0;
    string num = to_string(n);
    sort(num.begin(), num.end(), [](char a, char b){ return a > b; });
	//아래도 가능하다
    //sort(num.begin(), num.end(), greater<int>());
    answer = stoll(num);		//string to long long
    return answer;
}

/////////////////////////////////////////////////////////////

#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

//sort를 사용하지 않고 priority_queue를 사용한 방법
long long solution(long long n) {
    long long answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    while (n){
        pq.push(n % 10);
        n = n / 10;
    }
    long long mul = 1;
    while (!pq.empty()){
        answer += pq.top() * mul;
        mul = mul * 10;
        pq.pop();
    }
    return answer;
}
