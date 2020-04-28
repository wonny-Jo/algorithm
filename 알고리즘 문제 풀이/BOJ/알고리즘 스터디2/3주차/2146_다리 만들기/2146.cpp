#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int d[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
bool map[101][101];
int N;
int land[101][101] = { 0 }; //섬 표시
bool visit[101][101];

bool isRange(int y, int x)
{
	if (y < 0 || y >= N || x < 0 || x >= N)
		return false;
	return true;
}

void bfs_land(int i, int j, int cnt) //섬을 구분하기위해 섬마다 번호붙임
{
	land[i][j] = cnt;
	queue<pair<int, int>> q;
	q.push({ i,j });

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + d[i][0];
			int nx = x + d[i][1];
			if (isRange(ny, nx)&&map[ny][nx]==1 && land[ny][nx] == 0)
			{
				land[ny][nx] = cnt;
				q.push({ ny,nx });
			}
		}
	}
}

int bfs(int num)  //해당 num으로부터 다른 섬까지의 최단거리 찾음
{
	queue<pair<pair<int, int>,int>> q;
	// 섬의 위치들을 다 넣어놓고 시작
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (land[i][j] == num)
				q.push({ { i,j },0 });

	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + d[i][0];
			int nx = x + d[i][1];
			if (isRange(ny, nx))
			{
				if (map[ny][nx] == 0&&visit[ny][nx]==0)//바다중 아직 방문안한곳
				{
					visit[ny][nx] = 1;
					q.push({ {ny,nx},cnt + 1 });
				}
				else if (land[ny][nx]&&land[ny][nx] != num) //섬인데 출발지와다른섬일때
					return cnt;
			}
		}
	}

}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> map[i][j];

	int cnt = 1;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
		{
			if (map[i][j] == 1 && land[i][j] == 0)
			{
				bfs_land(i, j, cnt);
				++cnt;
			}
		}

	int ret = 10000;
	for (int i = 1; i < cnt; i++)
	{
		memset(visit, 0, sizeof(visit));
		ret = min(ret, bfs(i));
	}
	cout << ret;

	return 0;
}