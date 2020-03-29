#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> budgets, int M) {
	int answer = 0;
	int max = M;
	int min = 0;
	sort(budgets.begin(), budgets.end());

	long long minisum = 0;
	for (int i = 0; i < budgets.size(); i++) minisum += budgets[i];

	//budgets을 다 합친것이 총 예산보다 작거나 같다면
	//budgets의 가장 큰 값을 리턴한다
	if (minisum <= M) {
		int k = budgets[budgets.size() - 1];
		return k;
	}

	//예산 배정 후 소모된 예산
	long long sum = 0;
	//이전의 이분탐색 값
	int pretmp = 0;
	//현재 이분탐색 값
	int tmp = 0;
	while (1) {
		pretmp = tmp;
		sum = 0;
		//max(M)과 min(0)의 중간 값
		tmp = (max + min) / 2;

		//각각의 budgets의 값과 중간값을 비교하여
		//중간 값이 크다면 budget을 아니라면 budget을 sum에 더해준다
		for (int i = 0; i < budgets.size(); i++)
		{
			if (tmp < budgets[i]) sum += tmp;
			else sum += budgets[i];
		}

		//중간값으로 budget을 확인 결과 sum이
		//M보다 크다면 max를 중간값으로 바꿔준다
		if (M < sum) max = tmp;
		//M보다 작다면 min을 중간값으로 바꿔준다
		else if (sum < M) min = tmp;

		//값의 변화가 없다면
		if (pretmp == tmp) return tmp;
	}

	return answer;
}
