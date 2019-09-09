#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> nums){
    sort(nums.begin(), nums.end());
    //nums.size()의 반을 얻을 수 있다
    int gett = nums.size() / 2;
    vector<int> v;
    v.push_back(nums[0]);
    int idx = 0;
    int kind = 1;
    for (int i = 1; i < nums.size(); i++){
        //같은 종류면 continue
        if (v[idx] == nums[i]) continue;
        
        //다른 종류를 만나면 넣어주고 idx++, kind++
        v.push_back(nums[i]);
        idx++;
        kind++;
    }
    
    //얻을 수 있는 포켓몬보다 종류가 많다면 얻을 수 있는 포켓몬의 수를 return
    if (kind > gett) return gett;
    
    //아니라면 종류를 리턴
	  return kind;
}
