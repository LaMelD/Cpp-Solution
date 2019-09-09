#include <string>
#include <vector>

using namespace std;

//황금비율
long long solution(int N)
{
	long long post = 0;
	long long now = 0;
	long long dulrea = 0;

	for (int i = 0; i < N; i++)
	{
		if (i == 0)
		{
			post = 1;
			dulrea = post * 4;
			continue;
		}
		else if (i == 1)
		{
			now = 1;
			dulrea += now * 2;
		}
		else
		{
			long long tmp = post;
			post = now;
			now = tmp + now;
			dulrea += now * 2;
		}
	}

	return dulrea;
}
