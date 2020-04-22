#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> v[501];
bool visit[501] = { 0 };

int bfs(int start)
{
	visit[start] = 1;
	queue<pair<int, int>> q;
	q.push({ start, 0 });
	int ret = 0;
	while (!q.empty())
	{
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (cnt == 3)
			break;
		++ret;
		int size = v[x].size();
		for (int i = 0; i < size; i++)
		{
			int y = v[x][i];
			if (!visit[y])
			{
				visit[y] = 1;
				q.push({ y,cnt + 1 });
			}
		}
	}
	return ret - 1;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	cout<<bfs(1);
	
	return 0;
}