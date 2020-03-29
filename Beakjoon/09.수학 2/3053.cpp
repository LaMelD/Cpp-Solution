#include <iostream>
#include <cmath>

using namespace std;

//파이 정의 부분에서 틀렸었다
const double PI = acos(-1.0);

int main()
{
	double r;
	cin >> r;

	double a = r * r * PI;
	double b = 2 * r * r;

	printf("%.6lf\n", a);
	printf("%.6lf\n", b);

	return 0;
}
