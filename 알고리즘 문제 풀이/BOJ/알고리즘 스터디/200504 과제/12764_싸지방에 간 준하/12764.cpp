#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int N;
int cnt[100001] = { 0 };
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> visit; //방문가능한 위치중 가장 낮은것
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //끝나는 시간, 넣은 위치

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int p, q; cin >> p >> q;
		v.push_back({ p,q });
		visit.push(i);
	}
	sort(v.begin(), v.end()); //넣는 순서가 빠른것부터 정렬

	int maxCnt = 0;
	for (int i = 0; i < N; i++)
	{
		while(!pq.empty()&&pq.top().first<v[i].first) //넣을 시간보다 적은 것들은 뺀다.
		{
			visit.push(pq.top().second);
			pq.pop();
		}

		int pos = visit.top(); //넣을 수 있는 것들중 가장 작은 위치를 찾아서 넣는다.
		visit.pop();
		pq.push({ v[i].second,pos });
		++cnt[pos];
		maxCnt = max(maxCnt, pos);
	}
	cout << maxCnt + 1 << '\n';
	for (int i = 0; i <= maxCnt; i++)
		cout << cnt[i] << ' ';
	
	return 0;
}
