#include<iostream>
#include<vector>
#include<string.h>
#include<queue>
using namespace std;
int N, M;
vector<pair<int, int>> v[10001];
bool visit[10001];

bool bfs(int start, int goal, int num)
{
	queue<int> q;
	q.push(start);
	visit[start] = 1;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		if (x == goal)
			return true;

		int size = v[x].size();
		for (int i = 0; i < size; i++)
		{
			int y = v[x][i].first;
			if (!visit[y] && num <= v[x][i].second)
			{
				visit[y] = 1;
				q.push(y);
			}
		}
	}
	return false;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	int low = 0, high = 0;
	for (int i = 0; i < M; i++)
	{
		int A, B, C; cin >> A >> B >> C;
		v[A].push_back({ B,C });
		v[B].push_back({ A,C });
		if (high < C)
			high = C;
	}
	int start, goal; cin >> start >> goal;
	int ret = 0;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		memset(visit, 0, sizeof(visit));
		if (bfs(start,goal,mid))
		{
			if (ret < mid)
				ret = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	cout << ret;

	return 0;
}