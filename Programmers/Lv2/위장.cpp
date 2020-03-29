#include <string>
#include <vector>

using namespace std;

struct node
{
	string kind;
	int nums;
};

int solution(vector<vector<string>> clothes)
{
	//wardrobe에 이미 옷 종류가 배치되어 있는지 확인을 위한 flag
	bool flag;
	vector<node> wardrobe;
	node _push;
	for (int i = 0; i < clothes.size(); i++)
	{
		flag = true;
		for (int j = 0; j < wardrobe.size(); j++)
		{
			//wardrobe에 옷 종류가 배치되어 있다면
			if (clothes[i][1] == wardrobe[j].kind) {
				//개수를 올려주고 flag를 false로 바꾼뒤 for문을 빠져나간다
				wardrobe[j].nums++;
				flag = false;
				break;
			}
		}
		//wardrobe에 옷 종류를 새로 배치해야 한다면
		if (flag)
		{
			//옷 종류
			_push.kind = clothes[i][1];
			//착용하지 않는 것 + 착용하는 것 
			//두가지로 생각하여 2를 push한다
			_push.nums = 2;
			wardrobe.push_back(_push);
		}
	}

	//옷을 골라입는 모든 경우의 수
	int ans = 1;
	for (int i = 0; i < wardrobe.size(); i++)
	{
		ans *= wardrobe[i].nums;
	}
	//아무것도 안입는 경우를 제외해야 하므로 1을 빼준다
	return ans - 1;
}
