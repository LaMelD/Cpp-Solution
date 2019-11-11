using namespace std;

int getgcd(int a, int b)
{
	int big = a < b ? b : a;
	int small = a < b ? a : b;

	while (1)
	{
		int tmp = big % small;
		if (tmp == 0)
		{
			break;
		}
		big = small;
		small = tmp;
	}

	return small;
}

long long solution(int w, int h)
{
	long long answer = (long long)w * (long long)h;

	int gcd = getgcd(w, h);

	long long lw = (long long)w / (long long)gcd;
	long long lh = (long long)h / (long long)gcd;

	long long minus = lw + lh - 1;
	minus = minus * (long long)gcd;

	answer -= minus;

	return answer;
}
