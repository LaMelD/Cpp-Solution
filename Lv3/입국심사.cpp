#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times)
{
	long long answer = 0;
	int size = times.size();

	sort(times.begin(), times.end());

	//가장 작은 심사시간을 min으로
	long long min = times[0];
	//가장 큰 심사시간 * (심사받을 사람 수)를 max로
	long long max = (long long)times[size - 1] * (long long)n;

	long long mid;
	//min이 더 이상 min이 아닐 때 (역전 할 때)까지
	while (min <= max)
	{
		//총 걸린 심사시간이 mid일 때 심사 받은 사람의 수
		long long tmp = 0;
		//심사시간 mid를 만든다
		mid = (min + max) / 2;
		for (int i = 0; i < size; i++)
		{
			//현재 심사시간 동안 심사관[i]가 심사 할 수 있는 사람수를 추가
			tmp += mid / times[i];

			//총 걸린 심사시간이 mid일 때 심사받은 사람이 n보다 크다면 정답이 아니므로
			//break
			if (tmp > n) break;
		}

		//tmp가 n보다 크다 == 심사시간이 길다
		//while을 빠져나갈 수 있도록 mid - 1을 max에 넣는다(또한 오차를 없애기 위해)
		if (tmp >= n) max = mid - 1;
		//tmp가 n보다 작다 == 심사시간이 짧다
		//while을 빠져나갈 수 있도록 mid + 1을 min에 넣는다(또한 오차를 없애기 위해)
		else if (tmp < n) min = mid + 1;
	}

	return min;
}
