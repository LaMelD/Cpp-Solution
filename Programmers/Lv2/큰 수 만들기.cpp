#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
	string answer = "";

	int idx = 0;
	while (k) {
		if (idx + 1 > number.length() - 1) {
			break;
		}

		if (number[idx] < number[idx + 1]) {
			number.erase(idx, 1);
			idx = 0;
			k--;
		}
		else {
			idx++;
		}
	}

	for (int i = 0; i < k; i++) {
		number.pop_back();
	}

	return answer = number;
}
