#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//sort를 위한 cmp함수
bool cmp(string a, string b) 
{
	char af, bf;
  int asize = a.size(), bsize = b.size();
	int len = asize > bsize ? asize : bsize;
	int ai = 0, bi = 0;
	for (int i = 0; i <= len; i++) 
  {
		af = a[ai];
		bf = b[bi];

		if (af == bf)
		{
			ai = (ai + 1) % asize;
			bi = (bi + 1) % bsize;
			continue;
		}

		return af > bf;
	}
	return false;
}

string solution(vector<int> numbers) 
{
	string answer = "";
	vector<string> num_str;

	for (int i = 0; i < numbers.size(); i++) 
  {
		num_str.push_back(to_string(numbers[i]));
	}

	int zero = 0;
	sort(num_str.begin(), num_str.end(), cmp);

	for (int i = 0; i < num_str.size(); i++) 
  {
		answer += num_str[i];
    //num_str배열에 있는 string이 "0" 이라면 zero++ 해준다
		if (num_str[i] == "0") zero++;
	}
  
  //num_str이 "0"으로만 이루어진 배열인가
	if (num_str.size() == zero) answer = "0";

	return answer;
}
