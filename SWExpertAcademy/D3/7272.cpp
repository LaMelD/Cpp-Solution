#include <iostream>
#include <string>
#include <vector>

using namespace std;
//DIFF, SAME
string solution(string A, string B)
{
	if (A.length() != B.length())
		return "DIFF";

	for (int i = 0; i < A.length(); i++)
	{
		int a, b;
		switch (A[i])
		{
		//CEFGHIJKLMNSTUVWXYZ
		//구멍이 없는 경우
		case 'C':
		case 'E':
		case 'F':
		case 'G':
		case 'H':
		case 'I':
		case 'J':
		case 'K':
		case 'L':
		case 'M':
		case 'N':
		case 'S':
		case 'T':
		case 'U':
		case 'V':
		case 'W':
		case 'X':
		case 'Y':
		case 'Z':
			a = 0;
			break;
		//ADOPQR
		//구멍이 하나인 경우
		case 'A':
		case 'D':
		case 'O':
		case 'P':
		case 'Q':
		case 'R':
			a = 1;
			break;
		//B
		//구멍이 두개인 경우
		case 'B':
			a = 2;
			break;
		}
		switch (B[i])
		{
		//CEFGHIJKLMNSTUVWXYZ
		//구멍이 없는 경우
		case 'C':
		case 'E':
		case 'F':
		case 'G':
		case 'H':
		case 'I':
		case 'J':
		case 'K':
		case 'L':
		case 'M':
		case 'N':
		case 'S':
		case 'T':
		case 'U':
		case 'V':
		case 'W':
		case 'X':
		case 'Y':
		case 'Z':
			b = 0;
			break;
		//ADOPQR
		//구멍이 하나인 경우
		case 'A':
		case 'D':
		case 'O':
		case 'P':
		case 'Q':
		case 'R':
			b = 1;
			break;
		//B
		//구멍이 두개인 경우
		case 'B':
			b = 2;
			break;
		}
		if (a != b) return "DIFF";
	}

	return "SAME";
}

int main()
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		string A, B;
		cin >> A >> B;

		cout << '#' << tc << ' ';
		cout << solution(A, B) << '\n';
	}
}
