#include<iostream>
#include<vector>
#include<string.h>
#include<queue>
using namespace std;

vector<pair<int, int>> vec[100001];
int check[100001];
int dist[100001];
void bfs(int x)
{
	queue<int> q;
	q.push(x);
	check[x] = true;

	while (!q.empty())
	{
		int currentNode = q.front();
		q.pop();
		for (int i = 0; i < vec[currentNode].size(); i++)
		{
			if (check[vec[currentNode][i].first] == false)
			{
				check[vec[currentNode][i].first] = true;
				q.push(vec[currentNode][i].first);
				dist[vec[currentNode][i].first] = dist[currentNode] + vec[currentNode][i].second;
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int s;
		cin >> s;
		while (true)
		{
			int p;
			int w;
			cin >> p;
			if (p == -1)
				break;
			cin >> w;
			vec[s].push_back(make_pair(p, w));
		}
	}

	// 임의로 설정한 루트 1번으로부터의 거리를 구하기 위한 bfs탐색
	bfs(1);

	int farthest_point = 1;
	for (int i = 2; i <= n; i++) {
		if (dist[farthest_point] < dist[i])
			farthest_point = i;
	}

	memset(check, false, sizeof(check));
	memset(dist, 0, sizeof(dist));

	// 앞에서 찾은 점을 기준으로 다시 이로부터의 각 점의 거리를 구함
	bfs(farthest_point);

	for (int i = 1; i <= n; i++) {
		if (dist[farthest_point] < dist[i])
			farthest_point = i;
	}

	cout << dist[farthest_point] << "\n";
}

