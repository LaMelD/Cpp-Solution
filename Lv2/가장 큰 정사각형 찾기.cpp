#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b, int c) {
	int tmp = a < b ? a : b;
	tmp = tmp < c ? tmp : c;
	return tmp;
}

int max(int a, int b) {
	return a < b ? b : a;
}

int solution(vector<vector<int>> board) {
	int i_size = board.size();
	int j_size = board[0].size();
	//i_size, j_size가 각각 1일 경우 1을 만나는 순간 1을 리턴한다
	if (i_size == 1) {
		for (int j = 0; j < j_size; j++)
		{
			if (board[0][j] == 1)
				return 1;
		}
	}
	else if (j_size == 1)
	{
		for (int i = 0; i < i_size; i++)
		{
			if (board[i][0] == 1)
				return 1;
		}
	}

	int left, top, leto;
	bool flag;
	int mx = 0;
	for (int i = 1; i < i_size; i++)
	{
		for (int j = 1; j < j_size; j++)
		{
			if (board[i][j] == 0) continue;
			if (mx == 0) mx = 1;

			flag = true;
			//좌측, 상단, 좌측 상단의 board 값을 확인
			left = board[i][j - 1]; top = board[i - 1][j]; leto = board[i - 1][j - 1];
			//셋 중 하나라도 0이라면 flag 를 false로 바꾼다
			if (left == 0 || top == 0 || leto == 0)
				flag = false;

			if (flag)
			{
				//세 값 중에서 가장 작은 것을 골라 + 1 하여 board에 저장
				board[i][j] = min(left, top, leto) + 1;
				//mx 값을 교체한다
				mx = max(mx, board[i][j]);
			}
		}
	}

	return mx * mx;
}
