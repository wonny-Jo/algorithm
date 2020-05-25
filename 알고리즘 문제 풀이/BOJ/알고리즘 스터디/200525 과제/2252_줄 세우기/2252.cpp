#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int depth[32001] = { 0 };
vector<int> v[32001];
bool visit[32001] = { 0 };

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M; cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		++depth[b];
	}

	queue<int> q;
	for (int i = 1; i <= N; i++)
	{
		if (depth[i] == 0)
		{
			q.push(i);
			visit[i] = 1;
		}
	}

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		cout << x << ' ';

		int size = v[x].size();
		for (int i = 0; i < size; i++)
		{
			int y = v[x][i];
			if (!visit[y])
			{
				--depth[y];
				if (depth[y] == 0)
				{
					q.push(y);
					visit[y] = 1;
				}
			}
		}
	}

	for (int i = 1; i <= N; i++)
		if (!visit[i])
			cout << i << ' ';

	return 0;
}