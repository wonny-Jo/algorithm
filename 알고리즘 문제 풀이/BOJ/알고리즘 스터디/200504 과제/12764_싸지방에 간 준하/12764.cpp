#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int N;
int cnt[100001] = { 0 };
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> visit; //�湮������ ��ġ�� ���� ������
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //������ �ð�, ���� ��ġ

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
	sort(v.begin(), v.end()); //�ִ� ������ �����ͺ��� ����

	int maxCnt = 0;
	for (int i = 0; i < N; i++)
	{
		while(!pq.empty()&&pq.top().first<v[i].first) //���� �ð����� ���� �͵��� ����.
		{
			visit.push(pq.top().second);
			pq.pop();
		}

		int pos = visit.top(); //���� �� �ִ� �͵��� ���� ���� ��ġ�� ã�Ƽ� �ִ´�.
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
