#include <iostream>
#include <vector>

using namespace std;

//완전 2진 트리로 입력이 들어온다
//root와 서브트리로 나누어 출력한다
int main(int argc, char** argv)
{
	//입출력 가속
	cin.tie(NULL);
	cout.sync_with_stdio(false);

	int test_case;
	int T;
	cin >> T;
	int n;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;
		int idx = 1;
		for (int i = 0; i < n; i++)
		{
			idx = idx * 2;
		}
		idx = idx - 1;
		vector<int> nv(idx);
		for (int i = 0; i < idx; i++)
		{
			cin >> nv[i];
		}
		cout << '#' << test_case << " ";

		idx = idx / 2;
		while (idx != 0)
		{
			int num = 1;
			while (idx * num < nv.size())
			{
				int tmp = idx * num;
				cout << nv[tmp] << " ";
				nv.erase(nv.begin() + tmp);
				num += 2;
			}
			cout << "\n";
			idx = idx / 2;
		}

		for (int i = 0; i < nv.size(); i++)
		{
			cout << nv[i] << " ";
		}
		cout << "\n";

	}
	return 0;
}
