#include<iostream>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;
int d[4][2] = { {0,-1},{0,1},{1,0},{-1,0} };
string map[1001];
int N, M;
bool visit[1001][1001];
bool wall[1001][1001];

bool isRange(int y, int x)
{
	if (y < 0 || y >= N || x < 0 || x >= M)
		return false;
	return true;
}

int bfs(int i, int j)
{
	visit[i][j] = 1;
	queue<pair<pair<int, int>,int>> q;
	q.push({ {i,j},1 });

	int ret = 0;
	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		if (y == N - 1 && x == M - 1)
			return cnt;

		for (int i = 0; i < 4; i++)
		{
			int ny = y + d[i][0];
			int nx = x + d[i][1];
			if (isRange(ny, nx) && visit[ny][nx] == 0)
			{
				visit[ny][nx] = 1;
				q.push({ { ny,nx },cnt + 1 });
			}
		}
	}
	return 1000000;
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> map[i];
		for (int j = 0; j < M; j++)
			wall[i][j] = map[i][j] - '0';
	}

	int ret = 1000000;
	//벽을 한칸씩 부수면서 bfs 진행
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == '1')
			{
				memcpy(visit, wall, sizeof(wall));
				visit[i][j] = 0;
				ret = min(ret, bfs(0, 0));
			}
		}
	}
	if (ret == 1000000)
		cout << -1;
	else
		cout << ret;
	return 0;
}