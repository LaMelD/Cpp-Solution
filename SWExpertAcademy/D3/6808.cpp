#include <iostream>
#include <string>

using namespace std;

bool used[19];
int kyuyoung[9], inyoung[9];
int win, lose;
int total = ((18 * 19) / 2) / 2;

void solve(int idx, int kyu_score, int in_score)
{
	if (in_score > total || kyu_score > total)
	{
		int num = 1;
		for (int i = idx; i < 9; i++)
		{
			num = num * (9 - i);
		}

		if (kyu_score > total)
			win += num;
		else
			lose += num;

		return;
	}
	else {
		for (int i = 0; i < 9; i++)
		{
			if (!used[inyoung[i]])
			{
				used[inyoung[i]] = true;

				if (kyuyoung[idx] > inyoung[i])
					solve(idx + 1, kyu_score + kyuyoung[idx] + inyoung[i], in_score);
				else if (kyuyoung[idx] < inyoung[i])
					solve(idx + 1, kyu_score, in_score + kyuyoung[idx] + inyoung[i]);
				else
					solve(idx + 1, kyu_score, in_score);

				used[inyoung[i]] = false;
			}
		}
	}
}

int main()
{
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		int input, tmp = 0;
		win = lose = 0;
		memset(used, 0, sizeof(used));
		for (int i = 0; i < 9; i++)
		{
			cin >> input;
			kyuyoung[i] = input;
			used[input] = true;
		}
		for (int i = 1; i < 19; i++)
		{
			if (!used[i])
			{
				inyoung[tmp++] = i;
			}
		}
		memset(used, 0, sizeof(used));

		solve(0, 0, 0);

		cout << '#' << tc;
		cout << ' ' << win << ' ' << lose << endl;
	}
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

using namespace std;

vector<bool> used;
vector<int> kyuyoung;
vector<int> inyoung;
int win, lose;
int total = ((18 * 19) / 2) / 2;

void solve(int idx, int kyu_score, int in_score)
{
	if (in_score > total || kyu_score > total)
	{
		int num = 1;
		for (int i = idx; i < 9; i++)
		{
			num = num * (9 - i);
		}

		if (kyu_score > total)
			win += num;
		else
			lose += num;

		return;
	}
	else {
		for (int i = 0; i < 9; i++)
		{
			if (!used[inyoung[i]])
			{
				used[inyoung[i]] = true;

				if (kyuyoung[idx] > inyoung[i])
					solve(idx + 1, kyu_score + kyuyoung[idx] + inyoung[i], in_score);
				else 
					solve(idx + 1, kyu_score, in_score + kyuyoung[idx] + inyoung[i]);

				used[inyoung[i]] = false;
			}
		}
	}
}

int main()
{
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		int input;
		kyuyoung = vector<int>(9);
		inyoung.clear();
		used = vector<bool>(19, false);
		win = lose = 0;
		for (int i = 0; i < 9; i++)
		{
			cin >> input;
			kyuyoung[i] = input;
			used[input] = true;
		}
		for (int i = 1; i < 19; i++)
		{
			if (!used[i])
			{
				inyoung.push_back(i);
			}
		}
		used.clear();
		used = vector<bool>(19, 0);

		solve(0, 0, 0);

		cout << '#' << tc;
		cout << ' ' << win << ' ' << lose << endl;
	}
}
