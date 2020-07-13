#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
vector<int> v[401];
int n, k;
bool visit[401];
int bfs(int a,int b)
{
	memset(visit, 0, sizeof(visit));
	queue<int> q;
	q.push(a);
	visit[a] = 1;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		if (x == b)
			return -1;
		int size = v[x].size();
		for (int i = 0; i < size; i++)
		{
			int y = v[x][i];
			if (!visit[y])
			{
				q.push(y);
				visit[y] = 1;
			}
		}
	}

	memset(visit, 0, sizeof(visit));
	q.push(b);
	visit[b] = 1;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		if (x == a)
			return 1;
		int size = v[x].size();
		for (int i = 0; i < size; i++)
		{
			int y = v[x][i];
			if (!visit[y])
			{
				q.push(y);
				visit[y] = 1;
			}
		}
	}

	return 0;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int a, b; cin >> a >> b;
		v[a].push_back(b);
	}

	int s; cin >> s;
	for (int i = 0; i < s; i++)
	{
		int a, b; cin >> a >> b;
		cout << bfs(a, b) << '\n';
	}

	return 0;
}
