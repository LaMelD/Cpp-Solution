#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;

	//몸무게를 내림차순으로 정렬
	sort(people.begin(), people.end());

	//가장 적게 나가는 사람부터
	int left = 0;
	//가장 많이 나가는 사람부터
	int right = people.size() - 1;
	while (left <= right) {
		//적게 나가는 사람 + 많이 나가는 사람 <= 무게 제한 인가
		if (people[left] + people[right] <= limit) {
			//무게가 적게 나가는 사람을 태운다
			left++;
		}
		//무게가 많이 나가는 사람을 태운다
		right--;
		//배를 보낸다
		answer++;
	}

	return answer;
}
