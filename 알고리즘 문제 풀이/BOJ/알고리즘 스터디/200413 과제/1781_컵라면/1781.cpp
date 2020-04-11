#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
		return a.second > b.second;
	return a.first > b.first;
}


int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	vector<pair<int, int>> v;
	
	int N; cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int deadLine, numOfCupNoodle;
		cin >> deadLine >> numOfCupNoodle;
		v.push_back({ deadLine,numOfCupNoodle });
	}

	sort(v.begin(), v.end(), compare);
	v.push_back({ 0,0 });
	priority_queue<int, vector<int>, less<int>> maxHeap;
	int i = 0;
	int result = 0;
	for (int cnt = N; cnt >0; --cnt)
	{
		// cnt¶û °°À»¶§±îÁö ³Ö¾îÁÜ
		while (v[i].first == cnt)
		{
			maxHeap.push(v[i].second);
			++i;
		}

		if (v[i].first < cnt&&!maxHeap.empty())
		{
			result += maxHeap.top();
			maxHeap.pop();
		}
	}
	cout << result;

	return 0;
}