#include <string>
#include <vector>

using namespace std;

//만들어진 소수를 저장
vector<int> total;

//소수인지 판별
bool is_prime(string n)
{
	int num = stoi(n);
	if (num == 1) return false;
	if (num % 2 == 0)
	{
		if (num == 2) return true;
		return false;
	}
	for (int i = 3; i < num / 2; i++)
	{
		if (num % i == 0) return false;
	}
	return true;
}

//v     : 변하지 않는 원본 string numbers
//stack : 숫자가 쌓이는 string
//n     : 몇번째 반복인지 확인하기 위한
//idx   : 추가한 숫자의 numbers에서의 인덱스
//visit : 현재까지 방문한 idx 모임
void DFS(string &v, string stack, int n, int idx, vector<bool> visit)
{
  //만들어진 수가 소수인가
	if (is_prime(stack))
	{
		int num = stoi(stack);
		bool flag = true;
    //만들어진 소수가 total배열에 들어가 있는지 판별
		for (int i = 0; i < total.size(); i++)
		{
			if (total[i] == num)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			total.push_back(num);
		}
	}
	n++;
	if (n >= v.length()) return;
	visit[idx] = true;
	for (int i = 0; i < v.length(); i++)
	{
		if (visit[i]) continue;
	  DFS(v, stack + v[i], n, i, visit);
	}
}

int solution(string numbers)
{
  total.clear();
	int i, n_size = numbers.length();
	string stack;
	//visit을 모두 false로 초기화
	vector<bool> visit(n_size);

	//시작 숫자를 정한다.
	for (i = 0; i < n_size; i++)
	{
		stack = numbers[i];
		DFS(numbers, stack, 0, i, visit);
	}
	return total.size();
}
