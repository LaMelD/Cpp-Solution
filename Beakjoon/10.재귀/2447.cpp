#include <iostream>
#include <vector>
#include <string>

using namespace std;

//별을 찍을지 공백을 출력할지 판단하고 출력한다
void is_star(int x, int y, int n)
{
	if ((x / n) % 3 == 1 && (y / n) % 3 == 1)
		cout << ' ';
	else
	{
		if (n / 3 == 0)
			cout << "*";
		else
			is_star(x, y, n / 3);
	}
}

int main()
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			is_star(i, j, n);
		}
		cout << "\n";
	}
}