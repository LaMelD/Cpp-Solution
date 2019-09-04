#include <string>
#include <vector>

using namespace std;

int solution(string name) 
{
	int answer = 0;

	int name_len = name.length();
	string cpy_name = "";
  //name의 길이만큼 cpy_name에 A를 추가해준다
	for (int i = 0; i < name_len; i++) {
		cpy_name += 'A';
	}

	int cur = 0;
	while (1) {
		//현재 cur(cursor)에 해당하는 cpy_name과 name이 같은가
		if (cpy_name[cur] != name[cur]) {
			//'N'과 현재 커서의 name의 거리를 비교한다
			if (name[cur] > 'N') {
				cpy_name[cur] = name[cur];
				answer += 'Z' - name[cur] + 1;
			}
			else {
				cpy_name[cur] = name[cur];
				answer += name[cur] - 'A';
			}
		}

		//break condition
		if (cpy_name == name) break;

		//다음 바꿀 문자의 거리를 잰다
		//오른쪽으로 가서 바꿀 때
		int right_far = 0;
		int cur_tmp1 = cur;
		while (cpy_name[cur_tmp1] == name[cur_tmp1]) {
			right_far++;
			cur_tmp1++;
			cur_tmp1 = cur_tmp1 % name_len;
		}

		//왼쪽으로 가서 바꿀 때
		int left_far = 0;
		int cur_tmp2 = cur;
		while (cpy_name[cur_tmp2] == name[cur_tmp2]) {
			left_far++;
			if (cur_tmp2 == 0) cur_tmp2 = name_len - 1;
			else cur_tmp2--;
		}

		//어느쪽으로 가야 최소값이 나오는지 판단하여
    //다음 cur(cursor)의 위치를 결정한다
		if (right_far > left_far) {
			cur = cur_tmp2;
			answer += left_far;
		}
		else {
			cur = cur_tmp1;
			answer += right_far;
		}
	}

	return answer;
}
