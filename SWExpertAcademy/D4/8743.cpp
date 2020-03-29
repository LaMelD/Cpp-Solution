#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
	cin.tie(0);
	cout.sync_with_stdio(false);

	int  T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		ll R, B;
		string ans;

		cin >> R >> B;
		
		//항상 이기기 위해서 최선의 방법을 사용하므로 최후에는
		//한 쪽의 돌이 0이 되는 순간이 존재한다
		//KJ가 게임을 시작했으므로
		//한 쪽의 돌의 갯수가 0이 되었을 때 나머지 한 쪽에 남은 돌의 갯수가 1이하일 때만 
		//대환이 승리하게 된다
		R = R - B;
		if (R < 0)
		{
			R = (-1) * R;
		}

		if (R < 2)
		{
			ans = "DH";
		}
		else
		{
			ans = "KJ";
		}

		cout << '#' << tc << ' ';
		cout << ans << '\n';
	}

	return 0;
}
