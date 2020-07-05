# include <vector>
# include <string>
# include <map>

vector<int> solution(vector<string> gems) {
    map<string, int> gem_idx;
    int gem_size = gems.size();
    for (int i = 0; i < gem_size; i++)
    {
        gem_idx.insert(pair<string, int>(gems[i], 0));
    }

    int kind = gem_idx.size();

    // 종류가 하나라면 {1, 1}을 리턴한다.
    if (kind == 1)
    {
        return { 1, 1 };
    }

    int ans_left = -1;
    int ans_right = -1;
    int ans_len = -1;

    // 각 단계 마다의 종류와 갯수를 담아 둘 map
    map<string, int> temp;

    // 초기 세팅
    int left = 0;
    int right = 0;
    temp.insert(pair<string, int>(gems[left], 1));
    
    // right 또는 left가 사이즈를 넘어갈 때까지 반복한다.
    while (right < gem_size && left < gem_size)
    {
        // 모든 종류의 보석을 포함하고 있는 경우
        if (temp.size() == kind)
        {
            if (ans_len == -1)
            {
                ans_left = left;
                ans_right = right;
                ans_len = right - left;
            }
            else if ((right - left) < ans_len)
            {
                ans_left = left;
                ans_right = right;
                ans_len = right - left;
            }

            // left를 오른쪽으로 이동시킨다.
            // 포함되지 않을 보석의 종류가 0개가 되면 map에서 제거한다.
            temp.at(gems[left])--;
            if (temp.at(gems[left]) == 0)
            {
                temp.erase(gems[left]);
            }
            left++;
        }
        // 포함된 보석의 종류가 부족한 경우
        else
        {
            // right를 오른쪽으로 이동시켜 보석을 더 포함하게 한다.
            right++;
            // 사이즈를 넘어가면 브레이크
            if (gem_size <= right)
            {
                break;
            }
            // temp에 해당 보석의 종류가 없다면
            if (temp.find(gems[right]) == temp.end())
            {
                temp.insert(pair<string, int>(gems[right], 1));
            }
            // temp에 해당 보석의 종류가 있다면
            else
            {
                temp.at(gems[right])++;
            }
        }
    }

    return { ans_left + 1, ans_right + 1 };
}