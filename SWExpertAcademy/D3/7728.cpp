#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//중복제거 방법을 숙지하자
int solution(string s)
{
	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()),s.end());

	return s.length();
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		string s;
		cin >> s;
		cout << '#' << test_case << " ";
		cout << solution(s) << endl;
	}
	return 0;
}
