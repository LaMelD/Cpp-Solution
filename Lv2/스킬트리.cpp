#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int stsize = skill_trees.size();
    int ssize = skill.length();
    for (int i = 0; i < stsize; i++){
        //queue선언 및 초기화
        queue<char> q;
        //각 스킬트리들의 크기
        int stisize = skill_trees[i].length();
        for (int j = 0; j < stisize; j++){
            for (int k = 0; k < ssize; k++){
                //스킬트리에 들어있는 문자를 skill에 있는지 확인후
                //queue에 넣어준다
                if (skill_trees[i][j] == skill[k])
                    q.push(skill_trees[i][j]);
            }
        }
        
        int cnt = 0;
        bool check = true;
        while (!q.empty() && cnt < ssize){
            //queue가 비어있지 않고 허용되지 않는 스킬을 먼저 배운다면
            //check를 false로 변경후 while을 빠져나간다
            if (q.front() != skill[cnt]){
                check = false;
                break;
            }
            cnt++;
            q.pop();
        }
        if (check) answer += 1;
    }

    return answer;
}
