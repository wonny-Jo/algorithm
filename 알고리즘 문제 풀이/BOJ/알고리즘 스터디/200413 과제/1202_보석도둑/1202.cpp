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
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		int a, b; cin >> a >> b;
		v.push_back({ a,b });
	}
	for (int i = 0; i < K; ++i)
		cin >> C[i];
	
	sort(v.begin(), v.end());
	sort(C, C + K);

	priority_queue<int, vector<int>, less<int>> maxHeap;
	long long result = 0;
	int j = 0;
	for (int i = 0; i < K; ++i)
	{
		while (j<N&&C[i] >= v[j].first)
		{
			maxHeap.push(v[j].second);
			++j;
		}

		if (!maxHeap.empty())
		{
			result += maxHeap.top();
			maxHeap.pop();
		}
	}
	cout << result;
	return 0;
}