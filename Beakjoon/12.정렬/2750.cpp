//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> v;

	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;

		v.push_back(input);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
	{
		cout << v[i] << '\n';
	}

	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//직접구현
#include <iostream>

using namespace std;

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void quick_sort(int* arr, int start, int end)
{
	int pivot = arr[start];
	int left = start + 1;
	int right = end;

	while (left <= right)
	{
		while (arr[left] < pivot)
		{
			left++;
		}
		while (arr[right] > pivot)
		{
			right--;
		}

		if (left <= right)
		{
			swap(arr[left], arr[right]);
		}
	}

	if (start < end)
	{
		swap(arr[start], arr[right]);
		
		quick_sort(arr, start, right - 1);
		quick_sort(arr, right + 1, end);
	}
}

int main()
{
	int n;
	cin >> n;

	int* arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	quick_sort(arr, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << '\n';
	}

	return 0;
}
