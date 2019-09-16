#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> works) {
	sort(works.begin(), works.end());

	long long wsize = works.size();
	long long sum = 0;
	for (int i = 0; i < wsize; i++)
	{
		sum += works[i];
	}
	sum = sum - (long long)n;

	if (sum <= 0) return 0;

	long long ans = 0;
	long long mok = sum / wsize;
	long long namoji = sum % wsize;
	long long tmp = wsize;
	for (int i = 0; i < wsize; i++)
	{
		if (works[i] < mok)
		{
			ans += (works[i] * works[i]);

			tmp -= 1;
			sum -= works[i];

			if (sum <= 0)
				return ans;

			if (tmp > 0) {
				mok = sum / tmp;
				namoji = sum % tmp;
			}
		}
		else if (works[i] == mok && namoji > 0)
		{
			ans += (works[i] * works[i]);

			tmp -= 1;
			sum -= works[i];

			if (sum <= 0)
				return ans;

			if (tmp > 0) {
				mok = sum / tmp;
				namoji = sum % tmp;
			}
		}
		else
		{
			if (namoji == 0)
			{
				ans += (mok * mok);
			}
			else
			{
				ans += ((mok + 1) * (mok + 1));
				namoji--;
			}
		}
	}

	return ans;
}
