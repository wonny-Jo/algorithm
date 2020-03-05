#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };

bool c[51][51];
int M, N, K;
bool isRange(int y, int x)
{
	if (y < 0 || y >= N || x < 0 || x >= M)
		return false;
	return true;
}

void bfs(int y, int x)
{
	queue<pair<int, int>> q;
	q.push({ y,x });
	c[y][x] = 0;

	while (!q.empty())
	{
		int new_y = q.front().first;
		int new_x = q.front().second;
		q.pop();

		for (int direct = 0; direct < 4; ++direct)
		{
			int ny = new_y + dy[direct], nx = new_x + dx[direct];
			if (isRange(ny, nx) && c[ny][nx] == 1)
			{
				q.push({ ny,nx });
				c[ny][nx] = 0;
			}
		}
	}

}



int main()
{
	int T; cin >> T;
	int y, x;
	for (int i = 0; i < T; ++i)
	{
		memset(c, 0, sizeof(c));
		cin >> M >> N >> K;
		for (int j = 0; j < K; ++j)
		{
			cin >> x >> y;
			c[y][x] = 1;
		}
		int count = 0;
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < M; ++k)
			{
				if (c[j][k] == 1)
				{
					bfs(j, k);
					++count;
				}
			}
		}
		cout << count << endl;
	}
	

	return 0;
}