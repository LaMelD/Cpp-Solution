#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		unsigned long long n;
		cin >> n;
        	//일반식이 필요하다
		unsigned long long a = (n - 1) * (n - 1) * 2 + 1;
		unsigned long long b = n * n * 2 - 1;
        	//#test_case a b
        	//형식으로 출력
		cout << "#" << test_case << " " << a << " " << b << "\n";
	}
	return 0;
}
