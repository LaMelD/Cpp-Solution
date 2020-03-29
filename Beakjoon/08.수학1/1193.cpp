#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int x, y;
	x = y = 1;
	int tmp = 1;
	int plus = 2;
  //위로 올라갔는지 아래로 내려갔는지 판단
	bool flag = true;
	while (tmp < n)
	{
		tmp += plus;
		flag = plus % 2 == 0 ? true : false;
		plus++;
		x++;
	}

	tmp = tmp - n;
  //flag에 따라서 x, y값 조정
	if (flag)
	{
		y += tmp;
		x -= tmp;
	}
	else
	{
		y = x;
		x = 1;
		y -= tmp;
		x += tmp;
	}
	cout << x << '/' << y << endl;

	return 0;
}
