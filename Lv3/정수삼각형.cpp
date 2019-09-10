#include <string>
#include <vector>

using namespace std;

int max (int a, int b)
{
    return a > b ? a : b;
}

int solution(vector<vector<int>> triangle) 
{
    int answer = 0;
    int size = triangle.size();
    vector<vector<int>> v(size, vector<int>(size));
    v[0][0] = triangle[0][0];
    
    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            //왼쪽 끝
            if (j == 0)
            {
                //현재 위치의 오른쪽 위에 저장된 값을 더한다
                v[i][j] = v[i - 1][j] + triangle[i][j];
            }
            //오른쪽 끝
            else if (j == i)
            {
                //현재 위치의 왼쪽 위에 저장된 값을 더한다
                v[i][j] = v[i - 1][j - 1] + triangle[i][j];
            }
            //나머지 경우
            else 
            {
                //현재 위치의 왼쪽 위 값과 오른쪽 위 값을 비교하여 큰 값을 더한다
                v[i][j] = max(v[i - 1][j - 1], v[i - 1][j]) + triangle[i][j];
            }
            
            //마지막이라면 answer에 가장 큰 값을 저장한다
            if (i == size - 1) 
            {
                answer = max(v[i][j], answer);
            }
        }
    }
    return answer;
}
