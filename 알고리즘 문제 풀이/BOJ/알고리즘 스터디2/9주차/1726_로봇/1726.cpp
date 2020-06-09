#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int m[4][2] = { {0,1},{-1,0},{0,-1},{1,0} };//µ¿ºÏ¼­³²
int M, N;
bool arr[101][101];
int start[3], goal[3]; //y,x,dir

bool visit[101][101][4] = { 0 };

bool isRange(int y, int x)
{
	if (y < 0 || y >= M || x < 0 || x >= N)
		return false;
	return true;
}

int bfs(int y, int x,int dir)
{
	visit[y][x][dir] = 1;
	queue < pair<pair<int, int>, pair<int, int>>> q;//y,x,dir,cnt
	q.push({ {y,x},{dir,0} });
	while (!q.empty())
	{
		int ny = q.front().first.first;
		int nx = q.front().first.second;
		int ndir = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();

		if (ny == goal[0] && nx == goal[1] && ndir == goal[2])
			return cnt;
		if (!visit[ny][nx][(ndir + 1) % 4])
		{
			visit[ny][nx][(ndir + 1) % 4] = 1;
			q.push({ {ny,nx},{(ndir + 1) % 4,cnt + 1} });
		}
		if (!visit[ny][nx][(ndir + 3) % 4])
		{
			visit[ny][nx][(ndir + 3) % 4] = 1;
			q.push({ {ny,nx},{(ndir + 3) % 4,cnt + 1} });
		}
		int newY = ny;
		int newX = nx;
		for (int i = 0; i < 3; i++)
		{
			newY += m[ndir][0];
			newX += m[ndir][1];
			if (arr[newY][newX])
				break;
			if (isRange(newY, newX) && !visit[newY][newX][ndir])
			{
				visit[newY][newX][ndir] = 1;
				q.push({ {newY,newX},{ndir,cnt + 1} });
			}
		}
	}
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> M >> N;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	for (int i = 0; i < 3; i++)
		cin >> start[i];
	for (int i = 0; i < 3; i++)
		cin >> goal[i];

	--start[0]; --start[1];
	--goal[0]; --goal[1];
	if (start[2] == 1)
		--start[2];
	else if (start[2] == 4)
		start[2] = 1;
	if (goal[2] == 1)
		--goal[2];
	else if (goal[2] == 4)
		goal[2] = 1;

	cout << bfs(start[0], start[1], start[2]);

	return 0;
}