#include <string>
#include <vector>

using namespace std;

//모든 화폐가 무한히 있다
int solution(int n, vector<int> money)
{
	vector<int> dp(n + 1, 0);
	//0부터 n까지의 금액 중에서
	//첫번째 화폐단위만 사용하여만들 수 있는 금액을 1로 설정한다
	for (int i = 0; i <= n; i++)
	{
		dp[i] = (i % money[0] == 0) ? 1 : 0;
	}

	//두번째부터 마지막 화폐단위를 모두 확인한다
	for (int i = 1; i < money.size(); i++)
	{
		//현재 화폐단위로 j금액을 만들 수 있는지 알아내는
		//점화식
		for (int j = money[i]; j <= n; j++)
		{
			//첫번째 반복
			//dp[0] = 1이다.
			//dp[두번째 화폐단위] + dp[0] 은 >= 1이 된다
			//dp[두번째 화폐단위]에 이미 첫번째 화폐단위로 만들 수 있는 금액이라면
			//dp[두번째 화폐단위]는 2로 설정된다
			//두번째 실행에는 
			//dp[두번째 화폐단위 + 1] = dp[두번째 화폐단위 + 1] + dp[1]이 된다
			//따라서 점화식은
			//dp[j] = dp[j] + dp[j - money[i]];
			dp[j] = (dp[j] + dp[j - money[i]]) % 1000000007;
		}
	}

	int ret = dp[n];

	return ret;
}
