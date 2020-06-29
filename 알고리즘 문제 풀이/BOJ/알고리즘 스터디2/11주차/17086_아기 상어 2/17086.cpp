#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;
int m[8][2] = { {-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1} };
int arr[51][51];
bool visit[51][51];
int N, M;

bool isRange(int y, int x)
{
	if (y < 0 || y >= N || x < 0 || x >= M)
		return false;
	return true;
}

int bfs(int i, int j)
{
	queue<pair<pair<int, int>,int>> q;
	q.push({ {i,j},0 });
	visit[i][j] = 1;

	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int ny = y + m[i][0];
			int nx = x + m[i][1];
			if (isRange(ny, nx) && !visit[ny][nx])
			{
				if (arr[ny][nx] == 1)
					return cnt + 1;
				else
				{
					q.push({ {ny,nx},cnt + 1 });
					visit[ny][nx] = 1;
				}
			}
		}
	}
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];

	int ret = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!arr[i][j])
			{
				memset(visit, 0, sizeof(visit));
				ret = max(ret, bfs(i, j));
			}
		}
	}
	cout << ret;

	return 0;
}