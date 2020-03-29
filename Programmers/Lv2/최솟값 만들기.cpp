#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
	int answer = 0;
	//오름차순 정렬
	sort(A.begin(), A.end());
	//내림차순 정렬
	sort(B.begin(), B.end(), [](int a, int b)
		{
			return a > b;
		});

	//인덱스별로 곱해서 answer에 더해준다
	for (int i = 0; i < A.size(); i++)
	{
		answer += A[i] * B[i];
	}

	return answer;
}
