#include <vector>
#include <string>

using namespace std;

struct c_pos{
    int x = 5;
    int y = 5;
};

struct POS{
    bool from_top = false;
    bool from_bottom = false;
    bool from_right = false;
    bool from_left = false;
};

//좌표 내에 있는가?
bool can_move(c_pos a)
{
    if (0 <= a.x && a.x <= 10 && 0 <= a.y && a.y <= 10)
        return true;
    return false;
}

int solution(string dirs)
{
    //11 * 11 배열에서 (왼쪽에서 온 경우, 오른쪽에서 온 경우, 위에서 온 경우, 아래에서 온 경우) 배열을 만든다
    vector<vector<POS>> visit(11, vector<POS>(11));
    c_pos curr;
    c_pos next;
    
    int ans = 0;
    //U :: up, D :: down, L :: left, R :: right 로 이동
    for (int i = 0; i < dirs.length(); i++)
    {
        char dir = dirs[i];
        switch(dir)
        {
        case 'U':
            next.y += 1;
            break;
        case 'D':
            next.y -= 1;
            break;
        case 'L':
            next.x -= 1;
            break;
        case 'R':
            next.x += 1;
            break;
        }
        
        if (can_move(next))
        {
            switch(dir)
            {
            case 'U':
                if (!visit[next.x][next.y].from_bottom)
                {
                    visit[next.x][next.y].from_bottom = true;
                    visit[curr.x][curr.y].from_top = true;
                    ans++;
                }
                break;
            case 'D':
                if (!visit[next.x][next.y].from_top)
                {
                    visit[next.x][next.y].from_top = true;
                    visit[curr.x][curr.y].from_bottom = true;
                    ans++;
                }
                break;
            case 'L':
                if (!visit[next.x][next.y].from_right)
                {
                    visit[next.x][next.y].from_right = true;
                    visit[curr.x][curr.y].from_left = true;
                    ans++;
                }
                break;
            case 'R':
                if (!visit[next.x][next.y].from_left)
                {
                    visit[next.x][next.y].from_left = true;
                    visit[curr.x][curr.y].from_right = true;
                    ans++;
                }
                break;
            }
            curr.x = next.x;
            curr.y = next.y;
        }
        else 
        {
            next.x = curr.x;
            next.y = curr.y;
        }
    }
    
	return ans;
}
