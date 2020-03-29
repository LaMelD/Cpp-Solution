#include <iostream>

using namespace std;

int main()
{
	int score;
	cin >> score;
	if (score > 89) cout << "A" << endl;
	else if (score > 79) cout << "B" << endl;
	else if (score > 69) cout << "C" << endl;
	else if (score > 59) cout << "D" << endl;
	else cout << "F" << endl;
}
