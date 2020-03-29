#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//내림차순을 위한 cmp함수
bool cmp(int a, int b)
{
	if (a == b) return false;
	return a > b;
}

int solution(vector<int> citations)
{
	//배열을 내림차순으로 정렬
	sort(citations.begin(), citations.end(), cmp);
	int n = citations.size();
	//가장 큰 값을 h에 적용
	int h = citations[0];

	int index = 0;
	//h가 음수가 아닐 때 까지 반복
	while (h >= 0)
	{
		//h번 이상 인용된 논문의 수 index 확정
		for (int i = 0; i < n; i++)
		{
			//h번 인용된 논문이라면 index 수정하고 계속
			if (citations[i] == h)
				index = i;
			//h번 이상 이용된 논문이 아니라면 indx 수정 후 break;
			else if (citations[i] < h)
			{
				index = i;
				break;
			}
		}

		//citations[index]가 h번 이상 인용된 논문이고(&&) h번 이상 인용된 논문의 수가 h이상이면
		if (citations[index] >= h && index + 1 >= h)
			//h_index를 리턴
			return h;
		//citations[index]가 h번 이상 인용된 논문이 아니고(&&) h번 이상 인용된 논문의 수가 h이상이면
		else if (citations[index] < h && index >= h)
			//h_index를 리턴
			return h;

		//h_index를 -1 하여 반복
		h--;
	}

	//만족하는 h_index가 없다면
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
더 짧고 좋은 코드
/*
[1, 7, 0, 1, 6, 4]를 내림 차순으로 정렬하고
배열의 인덱스 0부터 1씩 증가시키면서 배열의 값과 비교한다
0 7
1 6
2 4
3 1
4 1
5 0
left(idx)와 right(citations[idx])를 비교하다가
인덱스에 해당하는 배열 값이 인덱스보다 작거나 같으면
해당 인덱스가 정답이다

[0, 0, 0, 0]
[5, 5, 5, 5, 5]과 같은 경우
0 5
1 5
2 5
3 5
4 5
해당하는 경우가 없기 때문에
while의 조건을 만족시키지 못하고 빠져나와
5를 리턴한다
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//내림차순을 위한 cmp함수
bool cmp(int a, int b)
{
	return a > b;
}

int solution(vector<int> citations)
{
	//배열을 내림차순으로 정렬
	sort(citations.begin(), citations.end(), cmp);
	int csize = citations.size();
	int idx = 0;

	while (idx < csize)
	{
		if (citations[idx] <= idx) break;
		idx++;
	}

	return idx;
}
