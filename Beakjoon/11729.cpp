#include <iostream>
#include <string>

using namespace std;

//n개를 from에서 by를 거쳐 to로 보낸다
//recursive하게 한다
string movehanoi(int n, int from, int by, int to, int& ans)
{
	ans++;
	string ret = "";
	if (n == 1)
	{
		ret += to_string(from) + " " + to_string(to) + "\n";
	}
	else
	{
		//n - 1개를 A에서 B로 옮겨 놓는다
		ret += movehanoi(n - 1, from, to, by, ans);
		//가장 아래 원판을 A에서 C로 옮겨 놓는다
		ret += to_string(from) + " " + to_string(to) + "\n";
		//B로 옮겨 놓은 n - 1개를 A로 다시 옮긴다
		ret +=movehanoi(n - 1, by, from, to, ans);
	}

	return ret;
}

int main(int argc, char** argv)
{
	//입출력 가속
	cin.tie(NULL);
	cout.sync_with_stdio(false);

	int n, ans = 0;
	string s;
	cin >> n;
	
	s = movehanoi(n, 1, 2, 3, ans);
	cout << ans << "\n" << s;

	return 0;
}