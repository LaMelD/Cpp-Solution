#include <iostream>

using namespace std;

int main()
{
	//입출력 가속
	cin.tie(NULL);
	cout.sync_with_stdio(false);

	int n;
	int result = 1;
	cin >> n;


	for (int i = 1; i <= n; i++) 
  {
		result = result * i;
	}

	cout << result << "\n";

	return 0;
}
