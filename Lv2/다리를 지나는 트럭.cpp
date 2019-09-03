#include <string>
#include <vector>
#include <queue>

using namespace std;

//answer를 시간으로 생각하여 1씩 증가시키는 방법
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    queue<int> _intobridge;
    queue<int> _inbridge;
    
    //들어가야하는 truck을 queue에 push한다
    for (int i = 0; i < truck_weights.size(); i++){
        _intobridge.push(truck_weights[i]);
    }
    
    //counter :: _inbridge에 truck이 push된 시간
    queue<int> counter;
    int out_truck;
    int in_truck;
    int _inbriwei = 0;
    
    do{
        answer++;
        int_truck = _intobridge.front();
        
        //bridge에 트럭이 들어가 있다면
        if (_inbridge.size() != 0){
            //bridge에 들어간 트럭이 통과했다면
            if (answer - counter.front() == bridge_length){
                out_truck = _inbridge.front();              //나가는 truck의 무게를 가져온다
                _inbriwei -= out_truck;                     //bridge에 들어가 있는 truck의 총 무게에 나가는 truck의 무게를 뺀다
                _inbridge.pop();                            //bridge에 들어가 있는 truck을 _inbridge큐에서 pop한다
                counter.pop();                              //truck이 bridge에 들어갔던 시간을 counter에서 pop한다
            }
        }
        
        //bridge에 들어가 있는 truck의 총 무게가 weight 이하이면
        if (_inbriwei + truck <= weight){
            _intobridge.pop();                  //bridge에 들어가야하는 truck을 _intobridge큐에서 pop해준다
            _inbridge.push(in_truck);           //bridge에 들어어가하는 truck을 _inbridge큐에 push한다
            _inbriwei += in_truck;              //bridge에 들어가 있는 truck의 총 무게에 들어가는 truck의 무게를 더한다
            counter.push(answer);               //truck이 bridge에 들어가는 시간(answer)을 counter에 push한다
        }
    }while (_intobridge.size() != 0);           //더 이상 들어갈 truck이 없으면 break;
    
    //마지막 truck이 bridge에 들어간 시간 + 마지막 truck이 bridge에서 빠져나가는 시간(bridge의 길이)
    return answer + bridge_length;
}
