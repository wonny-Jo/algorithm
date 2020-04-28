#include<iostream>
#include<queue>
using namespace std;
int d[4][2] = { {0,-1},{0,1},{1,0},{-1,0} };
string map[1001];
int N, M;
bool visit[1001][1001][2]; //2는 벽부셨는지 여부

bool isRange(int y, int x)
{
	if (y < 0 || y >= N || x < 0 || x >= M)
		return false;
	return true;
}

int bfs()
{
	visit[0][0][0] = 1;
	queue<pair<pair<int, int>,pair<int,int>>> q; //{{y,x},{cnt,벽부셨는지}}
	q.push({ {0,0},{1,0} });

	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cnt = q.front().second.first;
		int W = q.front().second.second;
		q.pop();
		if (y == N - 1 && x == M - 1)
			return cnt;

		for (int i = 0; i < 4; i++)
		{
			int ny = y + d[i][0];
			int nx = x + d[i][1];
			if (isRange(ny, nx))
			{
				if (map[ny][nx] == '1' && W == 0)
				//주변이 벽이며 아직 벽부수기 안했을경우
				{
					visit[ny][nx][W + 1] = 1;
					q.push({ { ny,nx },{cnt + 1,W + 1} });
				}
				else if (map[ny][nx] == '0' && !visit[ny][nx][W])
				//벽이 아니고 아직 방문한적이 없을때(일반적인 bfs)
				{
					visit[ny][nx][W] = 1;
					q.push({ { ny,nx }, { cnt + 1,W } });
				}
			}
		}
	}
	return -1;
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> map[i];

	cout << bfs();
	return 0;
}