#include <iostream>
#include <vector>

using namespace std;

//모든 관문 사이에 직접이동이 가능해야한다
int solution(int move_limit, vector<int> warp)
{
	int wsize = warp.size();
	int cnt = 0;
	int ret = 0;
	for (int i = 0; i < wsize; i++)
	{
		if (warp[i] == 1)
		{
			cnt = 0;
		}
		else
		{
			if (cnt == move_limit)
			{
				warp[i] = 1;
				ret++;
				cnt = 0;
			}
		}
		cnt++;
	}
	return ret;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		int move_limit;
		cin >> n >> move_limit;

		//0번째와 N + 1번째는 1로 만든다
		//warp 배열의 초기화
		vector<int> warp = { 1 };
		for (int i = 0; i < n; i++)
		{
			int push;
			cin >> push;
			warp.push_back(push);
		}
		warp.push_back(1);

		cout << '#' << test_case << " ";
		cout << solution(move_limit, warp) << endl;
	}
	return 0;
}
