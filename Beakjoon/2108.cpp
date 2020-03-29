#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int max(int a, int b)
{
	return a < b ? b : a;
}

int main()
{
	//cin.tie(NULL);
	//cout.sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> arr1;
	queue<int> q;
	int arr2[8004] = { 0, };
	double sum = 0;
	int input;
	int duple = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		sum += input;
		arr1.push_back(input);
		arr2[input + 4000]++;
		duple = max(duple, arr2[input + 4000]);
	}
	
	for (int i = 0; i < 8004; i++)
	{
		if (duple == arr2[i])
		{
			q.push(i);
		}
	}

	sort(arr1.begin(), arr1.end());
	sum = sum / n;
	printf("%.0lf\n", sum);
	cout << arr1[n / 2] << '\n';
	if (q.size() == 1)
	{
		cout << q.front() - 4000 << '\n';
	}
	else
	{
		q.pop();
		cout << q.front() - 4000 << '\n';
	}
	cout << arr1[n - 1] - arr1[0] << '\n';

	return 0;
}
