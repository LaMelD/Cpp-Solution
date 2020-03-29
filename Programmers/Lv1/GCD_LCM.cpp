#include <string>
#include <vector>

using namespace std;

//유클리드 호제법
int getGCD(int b, int s){
  int tmp;
	while (1) {
    tmp = b % s;
	  if (tmp == 0) break;
	  b = s;
		s = tmp;
	}
  return s;
}

vector<int> solution(int n, int m) {
	if (m == n) {
		return { m, n };
	}
  int big = n > m ? n : m;
  int small = n > m ? m : n;

  int gcd = getGCD(big, small);
	int lcm = (m * n) / gcd;
  
  return {gcd, lcm};
}
