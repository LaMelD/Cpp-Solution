#include <iostream>

using namespace std;

int main()
{
	int H, M;
	cin >> H >> M;
	if (M < 45)
	{
		H--;
		M += 60;
		if (H == -1) H = 23;
	}
	cout << H << " " << M - 45 << endl;
}
