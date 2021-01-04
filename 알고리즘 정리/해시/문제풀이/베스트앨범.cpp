#include <iostream>

///////////////////////////////////////////////////////////////////
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) 
{
	map<string, int> m;//노래 장르와 장르에 대한 index정보를 담는 map
	int idx = 1;
	int numOfGenres[101] = { 0 }; //장르의 재생 수
	vector<priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> v; //index에 따른 곡 재생수 정보 // 우선순위 큐는 오름차순으로 진행
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pqNull;
	v.push_back(pqNull); // 인덱스를 맞추기위해 빈 큐 하나 넣음
	int size = plays.size();
	for (int i = 0; i < size; i++)
	{
		if (m[genres[i]] == 0) //장르에 따른 인덱스 매칭
		{
			m[genres[i]] = idx;
			idx++;
			priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
			v.push_back(pq);
		}
		numOfGenres[m[genres[i]]] += plays[i]; //장르의 재생 수 업데이트

		//장르마다 최대 2개까지만 가장 많이 재생된 노래 정보를 가짐
		if(v[m[genres[i]]].size()<2)
			v[m[genres[i]]].push({ plays[i],i });
		else if (v[m[genres[i]]].size() == 2 && (plays[i] > v[m[genres[i]]].top().first || (plays[i] == v[m[genres[i]]].top().first && i < v[m[genres[i]]].top().second)))
		{
			v[m[genres[i]]].pop();
			v[m[genres[i]]].push({ plays[i],i });
		}
	}
	priority_queue<pair<int, int>> greaterSong; //가장 많이 재생된 장르부터 내림차순정렬
	for (int i = 1; i < idx; i++)
		greaterSong.push({ numOfGenres[i],i });
	
	vector<int> answer;
	//가장 많이 재생된 장르부터 각각 속한 노래 index를 정답에 넣음
	while (!greaterSong.empty())
	{
		int num = greaterSong.top().second;
		if (v[num].size() == 1) //속한 노래가 하나인 경우
		{
			answer.push_back(v[num].top().second);
			v[num].pop();
		}
		else //속한 노래가 2개인 경우
		{
			pair<int, int> fir = v[num].top();
			v[num].pop();
			pair<int, int> sec = v[num].top();
			v[num].pop();
			if (fir.first == sec.first) //두개가 같다는 것은 fir이 index도 더 낮을수밖에 없음
			{
				answer.push_back(fir.second);
				answer.push_back(sec.second);
			}
			else
			{
				answer.push_back(sec.second);
				answer.push_back(fir.second);
			}
		}
		greaterSong.pop();
	}
	return answer;
}

///////////////////////////////////////////////////////////////////

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	vector<string> genres = { "classic","pop","classic","classic","pop" };
	vector<int> plays = { 500,600,150,800,2500 };

	vector<int> ret = solution(genres, plays);
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << ' ';
	cout << '\n';
	return 0;
}