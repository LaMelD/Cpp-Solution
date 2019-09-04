#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book)
{
	bool flag;
	int min_size, i_size, j_size;
	int i, j, k;
	int psize = phone_book.size();

	for (i = 0; i < psize; i++)
	{
		for (j = 0; j < psize; j++)
		{
			//같은 인덱스 제외
			if (i == j)
				continue;

			//두 전화번호의 맨 앞자리가 같으면
			if (phone_book[i][0] == phone_book[j][0])
			{
				//초기화
				flag = true;
				i_size = phone_book[i].length();
				j_size = phone_book[j].length();
				//두 전화번호 중 짧은 전화번호의 길이
				min_size = i_size < j_size ? i_size : j_size;
				for (k = 1; k < min_size; k++)
				{
					//두 전화번호의 각 자리를 체크한다
					if (phone_book[i][k] == phone_book[j][k])
						continue;
					//하나라도 다른 것을 만나면 flag를 false로 하고 break;
					flag = false;
					break;
				}
				//두 전화번호 중에 짧은 전화번호가 긴 전화번호의 앞 자리와 같다면
				if (flag)
					return false;
			}
		}
	}

	//이상이 없으면 true 리턴
	return true;
}
