#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int N, K;
vector<pair<int, int>> v;
int C[300001];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		int a, b; cin >> a >> b;
		v.push_back({ a,b });
	}
	for (int i = 0; i < K; ++i)
		cin >> C[i];

	//오름차순 정렬
	sort(v.begin(), v.end());
	sort(C, C + K);

	priority_queue<int, vector<int>, less<int>> maxHeap;
	long long result = 0;
	int j = 0;
	for (int i = 0; i < K; ++i)
	{
		//현재 가방안에 넣을수 있는것은 다 넣어줌
		while (j < N && C[i] >= v[j].first)
		{
			maxHeap.push(v[j].second);
			++j;
		}
		//maxHeap에 있는 것중에서 가장 가격이 높은 하나만 빼서 더해줌
		if (!maxHeap.empty())
		{
			result += maxHeap.top();
			maxHeap.pop();
		}
	}
	cout << result;
	return 0;
}