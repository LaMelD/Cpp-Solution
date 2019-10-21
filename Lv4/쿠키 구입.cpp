#include <string>
#include <vector>
#include <iostream>

using namespace std;

int max(int a, int b)
{
	return a < b ? b : a;
}

int solution(vector<int> cookie)
{
	//가능한 모든 경우에서의 최대값을 저장한다
	int ret = 0;

	//mid를 0부터 마지막 전까지 확인한다
	int mid;
	int n = cookie.size();
	for (mid = 0; mid < n - 1; mid++)
	{
		//left를 mid로
		//right를 mid + 1로 
		//커서를 잡는다
		int left = mid;
		int right = mid + 1;

		//leftsum에 left커서의 값을 넣어주고
		//rightsum에 right커서의 값을 넣어준다
		int leftsum = cookie[left];
		int rightsum = cookie[right];

		while (1)
		{
			//leftsum과 rightsum이 같다면
			if (leftsum == rightsum)
			{
				//이전의 최대값과 비교한다
				ret = max(ret, leftsum);
			}

			//leftsum이 작다면
			if (leftsum < rightsum)
			{
				//left 커서를 왼쪽으로 이동한다
				left--;
				//범위 밖으로 나간다면 break
				if (left < 0)
				{
					break;
				}
				
				//아니라면 leftsum에 이동한 left 커서의 값을 더해준다
				leftsum += cookie[left];
			}
			//leftsum과  rightsum값이 같다면
			else if (leftsum == rightsum)
			{
				//left커서를 왼쪽으로
				//right커서를 오른쪽으로 밀어준다
				left--;
				right++;
				//둘 중 하나라도 범위를 벗어나면 break
				if (left < 0 || n <= right)
				{
					break;
				}

				//각각 sum에 커서값을 더해준다
				leftsum += cookie[left];
				rightsum += cookie[right];
			}
			//leftsum이 크다면
			else
			{
				//right커서를 오른쪽으로 이동한다
				right++;

				//범위를 벗어나면 break
				if (n <= right)
				{
					break;
				}

				//rightsum에 이동한 커서의 값을 더해준다
				rightsum += cookie[right];
			}
		}
	}

	return ret;
}
