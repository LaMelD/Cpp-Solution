#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> solution(int);

int main() {
	int T;
	cin >> T;
	int n;
	pair<int, int> ans;
	for (int tc = 0; tc < T; tc++) {
		cin >> n;
		ans = solution(n);
		cout << ans.first << " " << ans.second << endl;
	}
}

pair<int, int> solution(int n) {
	vector<pair<int, int>> v(41);
	int i;
	v[0] = { 1, 0 };
	v[1] = { 0, 1 };
	for (int i = 2; i <= n; i++) {
		v[i].first = v[i - 1].first + v[i - 2].first;
		v[i].second = v[i - 1].second + v[i - 2].second;
	}
	return v[n];
}
