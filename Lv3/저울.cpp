#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int solution(vector<int> weight) {
	int answer = 1;

	//오름 차순으로 정렬
	sort(weight.begin(), weight.end());

	//가장 작은 것의 무게가 1이 아니면
	//측정 불가능한 무게의 최소값은 1이다
	if (weight[0] != 1) {
		return 1;
	}
	//가장 작은 것의 무게가 1일 때
	else {
		int sum = weight[0];
		int size = weight.size();
		for (int i = 1; i < size; i++) {
			//이번에 확인 하는 추의 무게가 sum + 1보다 크다면
			//sum까지는 측정할 수 있고 sum + 1은 측정이 불가능 하다
			if (weight[i] > sum + 1) {
				break;
			}
			sum += weight[i];
		}
		answer = sum + 1;
	}
	return answer;
}
