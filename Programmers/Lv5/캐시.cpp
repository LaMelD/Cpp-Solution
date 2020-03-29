#include <string>
#include <vector>

using namespace std;

static const int hit = 1;
static const int miss = 5;

struct node {
	int used_time = -1;
	string city = "";
};

bool is_hit(vector<node>& c, string s, int time)
{
	for (int i = 0; i < c.size(); i++)
	{
		if (c[i].city == s)
		{
			c[i].used_time = time;
			return true;
		}
	}

	return false;
}

void cache_replace(vector<node>& c, string s, int time)
{
	int T = c[0].used_time;
	int idx = 0;
	
	for (int i = 1; i < c.size(); i++)
	{
		if (c[i].used_time < T)
		{
			T = c[i].used_time;
			idx = i;
		}
	}

	c[idx].used_time = time;
	c[idx].city = s;
}

int solution(int cacheSize, vector<string> cities) 
{
	int cnt = 0;

	int csize = cities.size();
	vector<node> cache(cacheSize);

	for (int i = 0; i < csize; i++)
	{
		for (int j = 0; j < cities[i].length(); j++)
		{
			cities[i][j] = toupper(cities[i][j]);
		}
	}

	for (int i = 0; i < csize; i++)
	{
		if (is_hit(cache, cities[i], cnt))
		{
			cnt += hit;
		}
		else
		{
			if (cacheSize != 0) 
			{
				cache_replace(cache, cities[i], cnt);
			}

			cnt += miss;
		}
	}

	return cnt;
}
