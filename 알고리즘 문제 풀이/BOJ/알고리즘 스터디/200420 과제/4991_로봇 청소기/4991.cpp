#include<iostream>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;
int direction[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int w, h;
string s[21];
bool visit[21][21];
int dist[21][21];

bool isRange(int y, int x)
{
	if (y < 0 || y >= h || x < 0 || x >= w)
		return false;
	return true;
}

void bfs(int i, int j)
{
	visit[i][j] = 1;
	queue<pair<pair<int, int>, int>> q;
	q.push({ {i, j},0 });

	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		dist[y][x] = cnt;

		for (int i = 0; i < 4; i++)
		{
			int ny = y + direction[i][0];
			int nx = x + direction[i][1];
			if (isRange(ny, nx) && !visit[ny][nx])
			{
				visit[ny][nx] = 1;
				q.push({ {ny,nx},cnt + 1 });
			}
		}
	}
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie();

	cin >> w >> h;
	while (w != 0 && h != 0)
	{
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < h; i++)
			cin >> s[i];

		int start[2];
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
			{
				if (s[i][j] == 'x')
					visit[i][j] = 1;
				if (s[i][j] == 'o')
				{
					start[0] = i; start[1] = j;
				}
				if (s[i][j] == '*')
					++N;
			}
		cout << bfs(start[0], start[1]) << '\n';
		cin >> w >> h;
	}

	return 0;
}