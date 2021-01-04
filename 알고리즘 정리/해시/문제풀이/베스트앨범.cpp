#include <iostream>

///////////////////////////////////////////////////////////////////
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) 
{
	map<string, int> m;//�뷡 �帣�� �帣�� ���� index������ ��� map
	int idx = 1;
	int numOfGenres[101] = { 0 }; //�帣�� ��� ��
	vector<priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> v; //index�� ���� �� ����� ���� // �켱���� ť�� ������������ ����
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pqNull;
	v.push_back(pqNull); // �ε����� ���߱����� �� ť �ϳ� ����
	int size = plays.size();
	for (int i = 0; i < size; i++)
	{
		if (m[genres[i]] == 0) //�帣�� ���� �ε��� ��Ī
		{
			m[genres[i]] = idx;
			idx++;
			priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
			v.push_back(pq);
		}
		numOfGenres[m[genres[i]]] += plays[i]; //�帣�� ��� �� ������Ʈ

		//�帣���� �ִ� 2�������� ���� ���� ����� �뷡 ������ ����
		if(v[m[genres[i]]].size()<2)
			v[m[genres[i]]].push({ plays[i],i });
		else if (v[m[genres[i]]].size() == 2 && (plays[i] > v[m[genres[i]]].top().first || (plays[i] == v[m[genres[i]]].top().first && i < v[m[genres[i]]].top().second)))
		{
			v[m[genres[i]]].pop();
			v[m[genres[i]]].push({ plays[i],i });
		}
	}
	priority_queue<pair<int, int>> greaterSong; //���� ���� ����� �帣���� ������������
	for (int i = 1; i < idx; i++)
		greaterSong.push({ numOfGenres[i],i });
	
	vector<int> answer;
	//���� ���� ����� �帣���� ���� ���� �뷡 index�� ���信 ����
	while (!greaterSong.empty())
	{
		int num = greaterSong.top().second;
		if (v[num].size() == 1) //���� �뷡�� �ϳ��� ���
		{
			answer.push_back(v[num].top().second);
			v[num].pop();
		}
		else //���� �뷡�� 2���� ���
		{
			pair<int, int> fir = v[num].top();
			v[num].pop();
			pair<int, int> sec = v[num].top();
			v[num].pop();
			if (fir.first == sec.first) //�ΰ��� ���ٴ� ���� fir�� index�� �� �������ۿ� ����
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