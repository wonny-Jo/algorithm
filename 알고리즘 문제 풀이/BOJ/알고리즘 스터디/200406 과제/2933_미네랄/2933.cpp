#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	int N, M; cin >> N >> M;
	vector<int> v[32001];
	int indegree[32001] = { 0 };
	priority_queue<int, vector<int>, greater<int>> minHeap;
	for (int i = 0; i < M; i++)
	{
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		++indegree[b];
	}

	for (int i = 1; i <= N; i++)
		if (!indegree[i])
			minHeap.push(i);
	
	while (!minHeap.empty())
	{
		int x = minHeap.top();
		minHeap.pop();
		cout << x << ' ';
		int size = v[x].size();
		for (int i = 0; i < size; ++i)
		{
			--indegree[v[x][i]];
			if (indegree[v[x][i]] == 0)
				minHeap.push(v[x][i]);
		}
	}

	return 0;
}