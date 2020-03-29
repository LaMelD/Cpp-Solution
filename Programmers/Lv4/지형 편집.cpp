#include <vector>
#include <iostream>
#define LLMAX 9223372036854775807LL;

using namespace std;

typedef long long ll;

int max(ll a, int b)
{
	return a < b ? b : a;
}

ll min(ll a, int b)
{
	return a < b ? a : b;
}

ll min(ll a, ll b)
{
	return a < b ? a : b;
}

//높이에 따라서 제거하고 추가하는 비용을 얻는다
ll getcost(vector<vector<int>>& land, ll h, int n, int P, int Q)
{
	long long ret = 0;
	long long p, q;
	p = q = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (land[i][j] < h)
			{
				p += h - land[i][j];
			}
			else
			{
				q += land[i][j] - h;
			}
		}
	}
	ret = (p * (ll)P) + (q * (ll)Q);

	return ret;
}

//이분탐색으로 풀었다
ll solution(vector<vector<int>> land, int P, int Q)
{
	int n = land.size();
	ll sum = 0;
	ll max_height = 0;
	ll min_height = LLMAX;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			sum += land[i][j];
			max_height = max(max_height, land[i][j]);
			min_height = min(min_height, land[i][j]);
		}
	}

	//land에서의 최대 높이와 최소 높이를 찾아
	//left와 right를 설정한다
	ll left = min_height;
	ll right = max_height;

	ll mid;
	while (left <= right)
	{
		//mid를 설정하여
		//높이가 mid일 때와 mid + 1일 때 각각의 코스트를 구한다
		//높이가 mid일 때의 코스트 : [0]
		//높이가 mid + 1일 때의 코스트 : [1]
		mid = (left + right) / 2;
		ll cost[2] = { getcost(land, mid, n, P, Q), getcost(land, mid + 1, n, P, Q) };

		//[0]과 [1]이 같다면
		//break
		if (cost[0] == cost[1])
		{
			break;
		}

		//[0]이 작다면 비용의 최솟값은 높이가 mid보다 작거나 같을 경우이기 때문에
		//right를 mid - 1로 해준다(mid일 가능성 있음)
		if (cost[0] < cost[1])
		{
			right = mid - 1;
		}
		//[0]이 크다면 비용의 최솟값은 높이가 mid보다 클 경우이기 때문에
		//left를 mid + 1로 해준다(mid일 가능성 없음)
		else
		{
			left = mid + 1;
		}
	}

	ll ret = LLMAX;
	//오차가 있을 수 있으므로 mid - 1부터 mid + 1까지의 비용의 최솟값을 구한다
	//단, mid - 1과 mid + 1은 0 이상 max_height 이하 구간에 있어야 한다
	for (int i = mid - 1; i <= mid + 1; i++)
	{
		if (0 <= i && i <= max_height)
		{
			ret = min(ret, getcost(land, i, n, P, Q));
		}
	}

	return ret;
}
