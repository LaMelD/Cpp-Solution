//합병 정렬 
//평균 시간복잡도 nlogn
//최악 시간복잡도 nlogn
//퀵 정렬
//평균 시잔복잡도 nlogn
//최악 시간복잡도 n^2
#include <iostream>
#include <vector>

using namespace std;

//머지 소트
void merge_sort(int* arr, int* arr2, int start, int end)
{
	int mid = (start + end) / 2;

	int left = start;
	int right = mid + 1;
	int ptr = start;

	while (left <= mid && right <= end)
	{
		if (arr[left] <= arr[right])
		{
			arr2[ptr++] = arr[left++];
		}
		else
		{
			arr2[ptr++] = arr[right++];
		}
	}

	int tmp = mid < left ? right : left;

	while (ptr <= end)
	{
		arr2[ptr++] = arr[tmp++];
	}

	for (int i = start; i <= end; i++)
	{
		arr[i] = arr2[i];
	}
}
void partition(int* arr, int* arr2, int start, int end)
{
	int mid;
	if (start < end)
	{
		mid = (start + end) / 2;
		partition(arr, arr2, start, mid);
		partition(arr, arr2, mid + 1, end);
		merge_sort(arr, arr2, start, end);
	}
}

int main()
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);

	int n;
	cin >> n;

	int* arr = new int[n];

	//정렬을 위한 공간
	int* arr2 = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	partition(arr, arr2, 0, n - 1);
	
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << '\n';
	}

	return 0;
}
