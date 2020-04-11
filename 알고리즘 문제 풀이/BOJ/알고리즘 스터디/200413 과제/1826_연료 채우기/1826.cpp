#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	int N; cin >> N;
	vector<pair<int, int>> v;
	for (int i = 0; i < N; ++i)
	{
		int a, b; cin >> a >> b;
		v.push_back({ a,b });
	}
	int L, P; cin >> L >> P;

	sort(v.begin(), v.end());

	priority_queue<int, vector<int>, less<int>> maxHeap;
	int cnt = 0;
	int i = 0;
	while (P < L)
	{
		while (i < N && v[i].first <= P)
		{
			maxHeap.push(v[i].second);
			++i;
		}

		if (maxHeap.empty())
		{
			cout << -1;
			return 0;
		}
		P += maxHeap.top();
		maxHeap.pop();
		++cnt;
	}
	cout << cnt;

	return 0;
}