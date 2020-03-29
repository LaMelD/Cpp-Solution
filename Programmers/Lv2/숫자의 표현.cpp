#include <string>
#include <vector>

using namespace std;

int solution(int n) 
{
    int answer = 0;
    int sum;
    
    for (int i = 1; i < n + 1; i++)
    {
        sum = 0;
        
        for (int j = i; j < n + 1; j++)
        {
            sum += j;
            
            if (sum > n) break;
            
            else if (sum == n)
            {
                answer++;
                break;
            }
        }
    }
    
    return answer;
}
