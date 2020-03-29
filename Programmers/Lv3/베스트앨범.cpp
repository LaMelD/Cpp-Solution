#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//노래의 고유번호와 재생횟수를 기록하는 구조체
struct song
{
	int id;
	int play;

	//우선순위 큐에 넣기 위한 비교 operator
	bool operator()(song a, song b)
	{
		if (a.play == b.play)
		{
			return a.id > b.id;
		}
		return a.play < b.play;
	}
};

//각각의 장르들의 정보를 기억하는 구조체
struct G
{
	string genre;
	//장르가 재생된 총 횟수
	int play = 0;
	//장르에 속한 노래들을 재생횟수가 높은 순서대로 저장하는 우선순위 큐
	priority_queue<song, vector<song>, song> id;
};

vector<int> solution(vector<string> genres, vector<int> plays) 
{
	vector<int> answer;

	//장르 배열을 만들어 준다
	vector<G> Genres;
	//각각의 인풋
	G Ginput;
	song sinput;
	//장르 배열의 파싱
	for (int i = 0; i < genres.size(); i++)
	{
		//장르에 이미 있는지 확인하는 flag
		bool is_in = false;

		//장르 배열을 확인
		for (int j = 0; j < Genres.size(); j++)
		{
			//안에 있다면
			if (Genres[j].genre == genres[i])
			{
				//총 플레이를 추가하고
				Genres[j].play += plays[i];
				//sinput을 조정하여
				sinput.id = i;
				sinput.play = plays[i];
				//장르배열 id큐에 넣어준다
				Genres[j].id.push(sinput);
				is_in = true;
				break;
			}
		}

		//안에 없다면 새롭게 추가
		if (!is_in)
		{
			//sinput을 조정
			sinput.id = i;
			sinput.play = plays[i];
			//Ginput을 조정
			Ginput.genre = genres[i];
			Ginput.play = plays[i];
			//sinput을 id큐에 넣어준다
			Ginput.id.push(sinput);
			//장르 배열에 추가
			Genres.push_back(Ginput);
			//Ginput의 id큐를 초기화
			Ginput.id.pop();
		}
	}

	//장르 배열을 총 플레이 횟수를 기준으로 정렬
	sort(Genres.begin(), Genres.end(), [](G a, G b)
		{
			return a.play > b.play;
		}
	);

	//베스트 앨범을 추출한다
	for (int i = 0; i < Genres.size(); i++)
	{
		//큐에 하나만 있다면 한개만 출력
		if (Genres[i].id.size() == 1)
		{
			answer.push_back(Genres[i].id.top().id);
			Genres[i].id.pop();
		}
		//두개 이상이라면 2개만 출력
		else
		{
			answer.push_back(Genres[i].id.top().id);
			Genres[i].id.pop(); 
			answer.push_back(Genres[i].id.top().id);
			Genres[i].id.pop();
		}
	}

	return answer;
}
