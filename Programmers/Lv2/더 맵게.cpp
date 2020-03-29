#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K) 
{
	int ans = 0;
  //스코빌 지수가 낮은 음식부터 들어가도록 priority_queu를 생성한다
	priority_queue<int, vector<int>, greater<int>> pq;
	int ssize = scoville.size();
  //K보다 스코빌 지수가 낮은 음식을 넣는다
	for (int i = 0; i < ssize; i++) 
	{
		if (scoville[i] < K) pq.push(scoville[i]);
	}
  
  //초기 pq에 들어가지 않은 갯수를 out_cnt에 넣는다
	int out_cnt = ssize - pq.size();
	int tmp;
  //pq가 비어있지 않은 순간까지 반복
	while (!pq.empty()) 
	{
    //pq.size() == 1 인가
		if (pq.size() == 1) {
      //스코빌 지수가 K이상인 것이 존재하는가
			if (out_cnt != 0) {
        //섞일 횟수 + 1;
				ans++;
				break;
			}
			else return -1;
		}

    //tmp = (스코빌 지수가 가장 낮은 음식) + (스코빌 지수가 두번째로 낮은 음식) * 2
		tmp = pq.top();
		pq.pop();
		tmp = tmp + pq.top() * 2;
		pq.pop();

    //tmp가 K보다 낮다면
		if (tmp < K) pq.push(tmp);
		else out_cnt++;

    //섞은 횟수 +1
		ans++;
	}
	return ans;
}
