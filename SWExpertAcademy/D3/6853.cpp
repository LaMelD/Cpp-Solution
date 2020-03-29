#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int n, x, y;
		cin >> n;

		int in = 0, on = 0, out = 0;

		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;

			//내부에 있으면
			if (x1 < x && x < x2 && y1 < y && y < y2)
			{
				in++;
			}
			//외부에 있으면
			else if (x < x1 || x > x2 || y < y1 || y2 < y)
			{
				out++;
			}
			//이외의 경우는 경계위에 있다
			else
			{
				on++;
			}
		}

		cout << '#' << tc << " ";
		cout << in << " " << on << " " << out << endl;
	}

	return 0;
}
