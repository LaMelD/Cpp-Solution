#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#include <iostream>

using namespace std;

struct node{
    int priority;       //priorities 의 우선순위
    int idx;            //priorities 배열에 담겨있던 idx
};

int solution(vector<int> priorities, int location) {
    queue<node> q;
    node n;
    int i, psize = priorities.size();
    
    //queue에 {priority, idx}순서로 넣어준다
    for (i = 0; i < psize; i++){
        n.priority = priorities[i];
        n.idx = i;
        q.push(n);
    }
    //priorities를 정렬하여 가장 큰 값이 뒤에 오도록 한다
    sort(priorities.begin(), priorities.end());
    
    int ans = 1;
    while (1){
        //확인하는 노드가 남아있는 것중에 가장 큰 우선순위인가
        if (q.front().priority == priorities.back()){
            //이번에 빠져나가는 node의 idx가 location과 같다면
            if (q.front().idx == location){
                return ans;
            }
            //빠져나가는 node의 우선순위를 priorities에서 pop해준다
            priorities.pop_back();
            q.pop();
            ans++;
        }
        else {
            //확인한 node를 맨 뒤로 보내준다
            q.push(q.front());
            q.pop();
        }
    }
    
    return -1;
}
